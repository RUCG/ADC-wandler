#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint16_t result;

uint16_t adc(void);

int main(void)
{

	result = 0;
	sei();
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0) | (1<<ADPS1);
	ADMUX |= ((1<<MUX0) | (1<<MUX1) | (1<<MUX2));
	ADMUX |= (1<<REFS1);
	ADCSRA |= (1<<ADSC);
	
	while(ADCSRA & (1<<ADSC));
	result = ADCW;
	
	while(1)
	{
	
		if(adc() > 511)
		{
			DDRA = 0xFF;
			DDRD = 0xFF;
			
			PORTA = 0xFF;
			PORTD = 0x00;
		}
	}//end of while
}//end of main

uint16_t adc(void)
{
			DDRA &= ~(1<<PA7);					//
			ADCSRA |= (1<<ADSC);				//
			while (ADCSRA & (1<<ADSC));		//
			result = ADCW;						//
			

return result;
}