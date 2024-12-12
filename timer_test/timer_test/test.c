#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 14745600UL // Set CPU clock to 1MHz

void timer1_init(void);

volatile uint8_t overflow_count = 0;

int main(void) {
	// Initialize Timer1
	timer1_init();

	// Set pin as output for toggling (e.g., PORTB0)
	DDRB |= (1 << PB0);

	while (1) {
		// Main loop does nothing; timer interrupt toggles the LED
	}
}

// Timer1 initialization
void timer1_init(void) {
	// Set Timer1 in Normal Mode (WGM13:0 = 0b0000)
	TCCR1A = 0;
	TCCR1B = (1 << CS12); // Prescaler = 256

	// Initial Timer Value
	TCNT1 = 0;

	// Enable Timer1 Overflow Interrupt
	TIMSK |= (1 << TOIE1);

	// Enable global interrupts
	sei();
}

// Timer1 Overflow Interrupt Service Routine
ISR(TIMER1_OVF_vect) {
	overflow_count++;

	// Generate approximately 1-second delay (adjust as needed)
	if (overflow_count >= 4) { // Adjust based on F_CPU and prescaler
		PORTB ^= (1 << PB0); // Toggle LED on PORTB0
		overflow_count = 0;
	}
}