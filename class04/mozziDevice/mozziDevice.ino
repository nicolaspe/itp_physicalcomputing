#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin8192_int8.h>

#define CONTROL_RATE 128
#define volumePot A0

// global setup
const int waveNumber = 9;

// led setup
int ledPin[waveNumber];

// audio setup
Oscil <2048, AUDIO_RATE> aSin_1(SIN8192_DATA);
Oscil <2048, AUDIO_RATE> aSin_2(SIN8192_DATA);
Oscil <2048, CONTROL_RATE> kVib(SIN8192_DATA);

float base_freq = 440.0;
float depth = 0.25;
byte volume;

void setup(){
  kVib.setFreq(6.5f);
  startMozzi(CONTROL_RATE);
  aSin_1.setFreq(440);
  aSin_2.setFreq(660);
}

void updateControl(){
  // volume control
  int sensor_value = mozziAnalogRead(volumePot);
  // map it to an 8 bit range for efficient calculations in updateAudio
  volume = map(sensor_value, 0, 1023, 0, 255); 

  // vibrato and sound update
  float vibrato = depth * kVib.next();
  aSin_1.setFreq(base_freq + vibrato);
}

int updateAudio(){
//  int finalSound = aSin_1.next() + aSin_2.next();
  int finalSound = aSin_1.next();
  return (finalSound * volume)>>8;
}

void loop(){
  audioHook();
}

