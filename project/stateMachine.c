#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"


void state_advance(){
  
  if(state == 1){
    mario_song();
    redLights();
    state = 0;
  }
  else if(state == 2){
    beethoven_5th();
    greenLights();
    state = 0;
  }
  else if(state == 3){
    path_of_wind();
    path_of_wind();
    bothLights();
    state = 0;
  }
  else if(state == 4){
    song_of_storms();
    bothLights();
    state = 0;
  }
  else{
    return;
  }
}
