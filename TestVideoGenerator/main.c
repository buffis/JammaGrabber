#define F_CPU 16000000  // CPU frequency delay timing.

#include <util/delay.h>
#include "utils.h"
#include "portsandpins.h"
#include <avr/interrupt.h>
#include <avr/io.h>

// VSYNC and HSYNC are active low, so starting means setting to 0.
#define START_VSYNC vsync = 0; SYNC_PORT &= ~VSYNC_PIN;
#define STOP_VSYNC  vsync = 1; SYNC_PORT |=  VSYNC_PIN;
#define START_HSYNC hsync = 0; SYNC_PORT &= ~HSYNC_PIN;
#define STOP_HSYNC  hsync = 1; SYNC_PORT |=  HSYNC_PIN;

// Clear CSYNC pin, and then set it to (HSYNC == VSYNC). TODO: Clean up/optimize.
#define UPDATE_CSYNC if (hsync == vsync) {SYNC_PORT |= CSYNC_PIN;} else {SYNC_PORT &= ~CSYNC_PIN;}

// These are used to produce composite sync, which is the negative XOR of VSYNC and HSYNC, or:
// CSYNC = (vsync == hsync);
BYTE vsync;  // ~60Hz, active low
BYTE hsync;  // ~15.4kHz, active low

#define LINES_HSYNC 8
#define LINES_BORDER_TOP 16
#define LINES_BORDER_BOTTOM 16
#define LINES_ACTIVE_AREA 224
#define LINES_TOTAL (LINES_HSYNC + LINES_BORDER_TOP + LINES_BORDER_BOTTOM + LINES_ACTIVE_AREA)
#define IS_LINE_IN_ACTIVE_AREA (linecounter >= 8+16 && linecounter < 8+16+224)
int linecounter = 0;  // Keeps count of the current line of a frame.

void setup() {
	// Setup outputs.
	MISC_DDR  |= LED_PIN;
	MISC_DDR  |= ERROR_PIN;
	COLOR_DDR |= ALL_COLOR_PINS;
	SYNC_DDR  |= (VSYNC_PIN | HSYNC_PIN | CSYNC_PIN);
	
	// Blink LED before starting. TODO: Maybe stop doing this?
	blink_led();

	// Start with sync pins disabled, and color set to zero.
	STOP_HSYNC
	STOP_VSYNC
	UPDATE_CSYNC
	COLOR_PORT = 0;

	// Setup interrupts.
	OCR1A = 1036;             // Compare to 16000000/15400 which is about 1038. TODO: Specify why value is different.
	TCCR1B |= (1 << WGM12);   // Mode 4, CTC on OCR1A
	TIMSK1 |= (1 << OCIE1A);  // Set interrupt on compare match
	TCCR1B |= (1 << CS10);    // Enable timer without prescaling
	sei();                    // Enable interrupts
}

void do_hsync() {
	START_HSYNC
	UPDATE_CSYNC
	_delay_us(5); // Hsync pulse should be about 5 usec.
	STOP_HSYNC
	UPDATE_CSYNC
}

// Draws the active area of a scanline.
// Note that this function needs to terminate before the next timer1 interrupt, which in practice means
// that this function must terminate in less than 1000 cycles or so.
void do_active_area() {
	int draw_color;
	int i;

	// The start color will be 0-56 based on the active line.
	// Four lines in a row will have the same starting color since the two least significant bits are discarded.
	draw_color = (linecounter - 24) >> 2;

	// Draw a black left border.
	for (i = 0; i < 5; i++) {
		COLOR_PORT = 0;
	}
	
	// Draw 76 horisontal color bars. Each color bar is separated by a white section.
	// 76 is picked by manual testing, and this works well with GCC 4.3.3 (through WINAVR).
	// TODO: Since the generated ASM might potentially differ between compilers, maybe change this to inline ASM.
	for (i = 0; i < 76; i++) {
		COLOR_PORT = 63; // White separator between bars.
		COLOR_PORT = draw_color & 63;
		draw_color++;
	}

	// After the color bars, change color to black to draw a right border.
	COLOR_PORT = 0;
}

void handle_line() {
	// VSYNC pulse should be during lines 0-7.
	if (linecounter == 0) {
		START_VSYNC
	}
	if (linecounter == 8) {
		STOP_VSYNC
	}

	// Each line should begin with a HSYNC pulse.
	do_hsync();

	if (IS_LINE_IN_ACTIVE_AREA) {
		do_active_area();
	}

	// Reset line counter once all lines have been displayed.
	if (++linecounter == LINES_TOTAL) {
		linecounter = 0;
	}
}

// This interrupt will trigger at approx 15.4khz when running on a 16mhz clocked CPU.
ISR (TIMER1_COMPA_vect)
{
	// Render a horizontal line, and generate sync pulses.
	handle_line();
}

int main(void) {
	setup();
	while (TRUE) {}  // Just loop while handling interrupts on timer1.
	return 0;
}
