/*
Timer
*/
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void timer_init(){
	//
	unsigned int value = 0x5A00;
	//
	OCR1AH = (value >> 8) & 0xFF;
	OCR1AL = (value & 0xFF);
	
	TCCR1A = ;
	TCCR1B = ;
}

int main(void){
	while(1){
		
	}
}