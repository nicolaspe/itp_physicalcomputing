/* SOUND SUBSTRACTION DEVICE
*  nicolás peña-escarpentier
*  Oct 2017 
*/

#include <MozziGuts.h>    // at the top of your sketch
#include <Oscil.h>  // a template for an oscillator
#include <tables/sin2048_int8.h>  // a wavetable holding a sine wave

#define CONTROL_RATE 128   // or some other power of 2

Oscil <2048, AUDIO_RATE> aSin_1(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_2(SIN2048_DATA);

// control variable, use the smallest data size you can for anything used in audio
byte gain = 255;


void setup(){
  startMozzi(CONTROL_RATE); // start with default control rate of 64
  aSin_1.setFreq(3320); // set the frequency
//  aSin_2.setFreq(440); // set the frequency
}


void updateControl(){
  // as byte, this will automatically roll around to 255 when it passes 0
  gain = gain - 3 ; 
}


int updateAudio(){
  int soundResult = aSin_1.next() +aSin_2.next();
//  return (soundResult* gain)>>8; // shift back to STANDARD audio range, like /256 but faster
  
  return (aSin_1.next()* gain)>>8; // shift back to STANDARD audio range, like /256 but faster
}


