#ifndef __TIMER_H
#define __TIMER_H

#define F_CPU 14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>	

void timer_init();

void toggle_led();

void init_leds();	

void timer_led_test();

void interrupt_test();

#endif //__TIMER_H