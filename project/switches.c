#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateAssembly.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  if (p2val == 1 && SW1 == 1){
    state_advance(1);
  }
  else if (p2val == 1 && SW2 == 1){
    state_advance(2);
  }
  else if (p2val == 1 && SW3 == 1){
    state_advance(3);
  }
  else if (p2val == 1 && SW4 == 1){
    state_advance(4);
  }
}
