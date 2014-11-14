#include <avr/io.h>
#include "PWM.h"

#define dutycycle OCR2A

void setupPWM(void){
  PORTB=0x00;
  DDRB=(1<<PB3); //We use PORTB3 as output, for OC2A
  //Setup PB3 as output
  DDRB |= (1<<3);
  PORTB |= (1<<3);
  // Mode: Phase correct PWM top=0xFF
  // OC2A output: Non-Inverted PWM
  TCCR2A=0x81;
  // Set the speed here, it will depend on your clock rate.
  TCCR2B=0x02;
}

void setDutyCycle(uint8_t duty){
  dutycycle=duty;
}

