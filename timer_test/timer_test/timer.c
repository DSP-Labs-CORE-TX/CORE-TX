#include "timer.h"

void timer_init(void){
	
	// value mic -> se stinge si se aprinde des
	// value mare -> interval mai mare
	unsigned int value = 0x3001; //7080
	
	OCR1AH = (value >> 8) & 0xFF;
	OCR1AL = value & 0xFF;
	
	TCCR1A = 0x00;
	TCCR1B = (1 << 3) | (1 << 2);
}

uint8_t led_count = 1;
uint8_t leds[]= {0};

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

// DDRB INIT
void init_leds(){
	for(uint8_t i = 0; i < led_count; i++)
	DDRB |= 1 << i;
}

void toggle_led(){
	switch_port_b(0);
}

void timer_led_test(){
	if((TIFR & (1 << 4)) != 0){
		toggle_led();
		
		//asta nu merge, de intrebat de ce
		//fprintf(stderr, "si nu merge si nu merge nicicum \n");
		
		TIFR |= 1 << 4;
	}
}

void interrupt_test(void){
	sei();
	timer_init();
	init_leds();
	
	TIMSK |= 1 << OCIE1A;
	
	while (1)
	{
	}
	
	cli();
}

