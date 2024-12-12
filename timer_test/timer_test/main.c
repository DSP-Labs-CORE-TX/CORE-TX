#include "timer.h"

int main(void){
	timer_init();
	init_leds();
	while(1){
		interrupt_test();
	}
}