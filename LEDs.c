#include <avr/io.h>
#include "LEDs.h"

void setupLEDs(void){
  //LEDs on PD2 PD3 PD4
  DDRD |= (1<<PD2|1<<PD3|1<<PD4);
  //LED on PB6;
  DDRB |= (1<<PB6);
  //Turn on all LEDs for intitialization
  PORTD |= (1<<PD2|1<<PD3|1<<PD4);
  PORTB |= (1<<PB6);
}
