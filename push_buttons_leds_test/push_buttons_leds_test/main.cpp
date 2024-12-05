/*
Created: 05.12.2024 12:24:25

Push Buttons and LEDs
*/
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define DOWN_BUTTON 0
#define UP_BUTTON 1
#define DEBOUNCE_DELAY_MS 10

uint8_t button_count = 2;
uint8_t led_count = 4;
uint8_t buttons[] = {0, 1};
uint8_t leds[]= {0, 1, 2, 3};

void set_port_b(uint8_t index){
	PORTB |= 1 << index;
}

void reset_port_b(uint8_t index){
	PORTB &= ~(1 << index);
}

void switch_port_b(uint8_t index){
	PORTB ^= 1 << index;
}

int check_pin_a(uint8_t index){
	return (PINA & (1 << index)) == 0;
}

// DDRA INIT
void init_push_buttons(){
	for(uint8_t i = 0; i < button_count; i++)
		DDRA |= 1 << i;
}

// DDRB INIT
void init_leds(){
	for(uint8_t i = 0; i < led_count; i++)
		DDRB |= 1 << i;
}

void button_move_led_down(uint8_t led_index){
	// first button -> move down
	if(check_pin_a(buttons[DOWN_BUTTON]))
	{
		_delay_ms(DEBOUNCE_DELAY_MS);
		// switch off led
		// increment led index
		// switch on led at new index
		
		if(check_pin_a(buttons[DOWN_BUTTON])){
			while(check_pin_a(buttons[DOWN_BUTTON]));
			reset_port_b(led_index);
			led_index = (led_index + 1) % led_count;
			set_port_b(led_index);
		}
	}
}

void button_move_led_up(uint8_t led_index){
	// second button -> move up
	if(check_pin_a(buttons[UP_BUTTON]))
	{
		_delay_ms(DEBOUNCE_DELAY_MS);
		// switch off led
		// decrement led index
		// switch on led at new index
		
		if(check_pin_a(buttons[UP_BUTTON])){
			while(check_pin_a(buttons[UP_BUTTON]));
			reset_port_b(led_index);
			led_index = (led_index + led_count - 1) % led_count;
			set_port_b(led_index);
		}
	}
}

int main(void){
	
	// Turn on the pins and ports for the buttons and leds
	init_leds();
	init_push_buttons();
	
	// Turn on the first led
	uint8_t led_index = 0;
	switch_port_b(leds[led_index]);	
	
	while(1){
		button_move_led_down(led_index);
		button_move_led_up(led_index);		
	}
}