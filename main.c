/*
* 2014-11-13, Gustaf Fjaestad, gustaf@fjaestad.nu
*
* ATMega88 based dimmer
* 
* 
* 
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

//Personal headers
#include <LEDs.h>
#include <PWM.h>
#include <incEncoder.h>

/*
volatile uint8_t PBhistory = 0xFF; //Default is high because of the pull ups

void initInterrupts(void){
  //Set PB1 and PB2 as inputs
  DDRB &= ~(1<<PB1);
  DDRB &= ~(1<<PB2);

  //Enable pull-up resistors
  PORTB |= (1<<PB1);
  PORTB |= (1<<PB2);
  
  PCICR |= (1<<PCIE0);
  PCMSK0 |= (1<<PCINT1);
}

*/
int main(void){
  setupLEDs();
  setupPWM();
  initInterrupts();
  sei(); //enable global interrupts
  
  while(1){
  }
}

int enc = 0;
ISR(PCINT0_vect){
  uint8_t rot=isCWRotation();
  if(rot==1){
    enc++;
  } else if(rot==0) {
    enc--;
  }
  
  //Check for overflow
  if(enc>255){
    enc=255;
  }
  if(enc<0){
    enc=0;
  }
  uint8_t enc8 = enc;
  setDutyCycle(enc8);
}

