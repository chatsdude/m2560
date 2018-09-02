/*
 * AVRGCC26.c
 *
 * Created: 18-08-2018 12:02:15
 *  Author: HP
 */ 

#include <avr/io.h>
void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/*Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);

}
/* Set frame format: 8data, 2stop bit */
unsigned char USART_Receive0( void )
{
/* Wait for data to be received */
while ( !(UCSR0A & (1<<RXC0)) )
;
/* Get and return received data from buffer */
return UDR0;}
void USART_Transmit0( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
	_delay_ms(100);
	
	
}
unsigned char USART_Receive1( void )
{
/* Wait for data to be received */
while ( !(UCSR1A & (1<<RXC1)) )
;
/* Get and return received data from buffer */
return UDR1;}
void USART_Transmit1( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) )
	;
	/* Put data into buffer, sends the data */
	UDR1 = data;
	_delay_ms(100);
	
	
}
void initADC()
{
	ADMUX=(1<<REFS0);				//Aref=AVcc
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);		//ADC enabled, Prescaler 64
}
int AnalogRead(int x)
{


//prescalar set to default
  ADMUX=(1<<REFS0)|(0<<REFS1);
  ADCSRA|=(1<<ADEN);
  ADMUX|=x;//chose value from 0 to 7 to chose adc pin accordingly
  ADCSRA|=(1<<ADEN);
  ADCSRA|=(1<<ADSC);
 while(ADCSRA&(1<<ADSC));
 return (ADC);
}



void Dmilli(int j)
{ 
	TCCR0A|=(1<<WGM01);
	TCCR0A|=(1<<CS00);
	TIMSK0|=(1<<OCIE0A);
	OCR0A=255;
	TCNT0=0;
long int x=31.50*j;
long	int i;
    for(i=0;i<x;i++)
    {
		while(!(TIFR0 & (1 << OCF0A))) 
        {
            
        }
        TIFR0|=(1<<OCF0A);
	} 

	}
	
 * AVRGCC8.c
 *
 * Created: 05-08-2018 14:23:19
 *  Author: HP
 */ 

#include <avr/io.h>
float x=0;
#include <avr/interrupt.h>
int millis()
{float l;
	l=x*0.16+0.00000625*TCNT0;
return l;
}

void tinit(void)
{ 
	TCCR0A|=(1<<WGM01);
	TCCR0A|=(1<<CS00);
	TIMSK0|=(1<<TOV0);
	TCNT0=0;
}

int main(void)
{
    
    tinit();
	DDRB=0b1111111;
	int y;
	sei();
	while (1)
	{
 y=millis();
 
 PORTB=y;
 	 
	}
        
    
}
ISR(TIMER0_OVF_vect)
{x++;	}	
	

int analogWrite(int pin,int duty)
{
  TCCR1B=(1<<CS11)|(1<<CS10);
  TCCR1A=(1<<WGM10)|(1<<WGM12)|(1<<COM1A1)|(1<<COM1B1);
  if(pin==1)
  {
    OCR1A=duty;
  }
  else if(pin==2)
  {
    OCR1B=duty;
  }
}





