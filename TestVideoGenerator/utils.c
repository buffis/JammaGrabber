#include <util/delay.h>
#include "portsandpins.h"
#include "utils.h"

void assert_or_die(BYTE value) {
	if (!value) {
		MISC_PORT |= ERROR_PIN;
		for (;;);
	}
}

void blink_led() {
	MISC_PORT |= LED_PIN;
	_delay_ms(1000);
	MISC_PORT &= ~LED_PIN;
	_delay_ms(1000);
	MISC_PORT |= LED_PIN;
} 