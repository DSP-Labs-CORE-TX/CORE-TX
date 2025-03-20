/*
 * sevenSegmentDisplay.c
 *
 * Created: 12.03.2025 12:41:53
 * Author : daria
 */ 

#define F_CPU 14745600UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

// aici este codificarea cifrelor pentru seven segment display
// 0 - activ, 1 - stins
// g f e d c b a
static const uint8_t digitmap[10] = {
	0xC0,		// 0 -> 1100 0000
	0xF9,		// 1 -> 1111 1001
	0xA4,		// 2 -> 1010 0100
	0xB0,		// 3 -> 1011 0000
	0x99,		// 4 -> 1001 1001	
	0x92,		// 5 -> 1001 0010
	0x82,		// 6 ->	1000 0010	
	0xF8,		// 7 -> 1111 1000
	0x80,		// 8 -> 1000 0000
	0x90		// 9 -> 1001 0000
};

// initializare 7 segment display -> toate led uri vor fi stinse -> 1111 1111
void init_digit(){
	DDRA = DDRA | 0xFF;
	PORTA = 0;
}

void display_digit(int i){
	PORTA = PORTA | digitmap[i];
}

void clear_digit(){
	PORTA = 0;
}

void change_number(){
		
}

int main(void)
{
    /* Replace with your application code */
	init_digit();
	
	_delay_ms(1000);
	
	//display_digit();
	//_delay_ms(300);
    while (1) 
    {
		for(int i = 0; i <= 9; i++){
			display_digit(i);
			_delay_ms(1000);
			clear_digit();
		}
    }
}

