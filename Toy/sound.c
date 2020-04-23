/* This is the 'buzz.c' i took from my project 2
   it'll play the buzzer consistently*/
#include <msp430.h>
#include "libTimer.h"
#include "sound.h"

void buzzer_init()
{
    /* P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero */
    timerAUpmode(); /* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6; /*output to speaker(P2.6) */
}

char buzzer_set_period(short cycles) /* buzzer clock = 2MHz(period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;/* one half cycle */
}

void loop(){
  short tone = buzzer_set_period(10000);

  for(int i=0; i<2;i++){
    if(i=1){
      tone= buzzer_set_period(1000);
    }
    if(i=2){
      tone= buzzer_set_period(10000);
    }
  }
}


    
    
  

