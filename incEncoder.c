#include <avr/io.h>
#include <avr/interrupt.h>

//Personal headers
#include <incEncoder.h>

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

uint8_t isCWRotation(void){
  uint8_t changedbits;
  changedbits = PINB ^ PBhistory;
  PBhistory = PINB;
  uint8_t ret=-1;

  if(changedbits & (1<<PB1)){
    //PCINT1 changed
    //check if fall or rise
    if(!(PBhistory & (1<<PB1))){ //if PB1 is not high (low), then we have a fall
      if(PBhistory & (1<<PB2)){
        ret=1;
      } else {
        ret=0;
      }
    }
  }
  
  return ret;
}
