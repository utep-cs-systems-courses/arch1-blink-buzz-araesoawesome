#include <msp430.h>
#include "timerLib/libTimer.h"
#include "buzzer.h"

//Defining note frequencies for songs
#define E4 1517
#define G4 1276
#define C4 1911
#define G3 2551
#define G5 638
#define F4 1432
#define Bb4 1073
#define D4 1703
#define F4 1432
#define D5 851


void buzzer_init(){
  timerAUpmode(); //speaker usage

  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  
  CCR1 = cycles >> 1; //defining cycles necesarry for speaker usage
}

void mario_song(){
  int sequence[] = {E4, 0, E4, 0, 0, E4, 0, 0, C4, 0, E4, 0, 0, G4, 0, 0, 0, 0, 0, 0, G3, 0, 0};

  for(int i = 0 ; i < sizeof(sequence)/sizeof(*sequence) ; i++){
    buzzer_set_period(sequence[i]);
    __delay_cycles(1200000);
  }
}

void beethoven_5th(){
  int sequence[] = {G5, 0, G5, 0, G5, 0, E4, E4, E4, E4, E4, E4, 0, 0, 0};

  for(int i = 0 ; i < sizeof(sequence)/sizeof(*sequence) ; i++){
    buzzer_set_period(sequence[i]);
    __delay_cycles(2400000);
  }
}

void path_of_wind(){
  int sequence[] = {C4, 0, Bb4, 0, G3, 0, C4, 0, 0, 0, Bb4, 0, G3, 0, 0, 0};

  for(int i = 0 ; i < sizeof(sequence)/sizeof(*sequence) ; i++){
    buzzer_set_period(sequence[i]);
    __delay_cycles(2400000);
  }  
}

void song_of_storms(){
  int sequence[] = {D4, 0, F4, 0, D5, D5, D5, 0, 0, 0, 0, D4, 0, F4, 0, D5, D5, D5, 0};

  for(int i = 0 ; i < sizeof(sequence)/sizeof(*sequence) ; i++){
    buzzer_set_period(sequence[i]);
    __delay_cycles(1200000);
  }
}
