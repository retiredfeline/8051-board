//
// Blink LED on P1_7
// This isn't a tutorial on C for the 8051, there are better ones
// This is just to test the board I made and learn to use SDCC
//

#include <8051.h>

#define	COUNT	4000
#define	TVAL	(65536-COUNT)

// assume 12 MHz clock so timer runs at 1 MHz
void delay4ms() __naked
{
	// let's see how good SDCC is at optimising this
	TH0 = TVAL >> 8;
	TL0 = TVAL & 0xFF;
	// pretty good according to generated assembler, just a spurious warning
	TR0 = 1;	// turn on T0
	while (TF0 == 0)
		;	// wait for overflow
	TF0 = 0;	// clear overflow
	TR0 = 0;
	__asm__("ret");
}

void delay(unsigned int ms)
{
	unsigned int	i = ms / 4;

	for ( ; i > 0; i--)
		delay4ms();
}

void main()
{
	TMOD = 0x1;
	for (;;) {
		P1_7 = 0;
		delay(500);
		P1_7 = 1;
		delay(500);
	}
}
