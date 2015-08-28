#ifndef PORTSANDPINS_H
#define PORTSANDPINS_H

#include <avr/io.h>

#define SYNC_DDR  DDRC
#define SYNC_PORT PORTC
#define VSYNC_PIN (1 << PC0)
#define HSYNC_PIN (1 << PC1)
#define CSYNC_PIN (1 << PC2)

#define MISC_DDR  DDRB
#define MISC_PORT PORTB
#define LED_PIN   (1 << PB0)
#define ERROR_PIN (1 << PB1)

#define COLOR_DDR DDRD
#define COLOR_PORT PORTD
#define ALL_COLOR_PINS 0x3F

#endif /* PORTSANDPINS_H */