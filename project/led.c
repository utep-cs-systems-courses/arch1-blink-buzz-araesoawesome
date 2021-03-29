#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  switch_state_changed = 1;
}

void greenLights(){
  for(int i = 0 ; i < 5 ; i++){
    P1OUT = LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(1000000);
  }
}

void redLights(){
   for(int i = 0; i < 5; i++){
    P1OUT = LED_RED;
    __delay_cycles(1000000);
    P1OUT = !LED_RED;
    __delay_cycles(1000000);
  }
}

void bothLights(){
  for(int blinks = 0; blinks < 5 ; blinks++){
    P1OUT = LED_RED;
    __delay_cycles(1000000);
    P1OUT = LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = !LED_RED;
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(1000000);
  }
}

//copied from led_update in demos
void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;
    ledFlags |= switch_state_down ? LED_RED : 0;
    ledFlags |= switch_state_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}
