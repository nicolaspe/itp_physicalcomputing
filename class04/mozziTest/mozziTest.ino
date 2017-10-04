#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

#define CONTROL_RATE 128
Oscil <2048, AUDIO_RATE> aSin_1(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_2(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_3(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_4(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_5(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_6(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_7(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_8(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> aSin_9(SIN2048_DATA);
Oscil <2048, CONTROL_RATE> kVib(SIN2048_DATA);

// firing & sensor setup
const int waveNumber = 9;
int waveGain[waveNumber];
int ledPin[waveNumber];
int occurrence = 50;
// time keeping from http://www.makeuseof.com/tag/arduino-delay-function-shouldnt-use/
unsigned long prevTime = 0;
int interval = 100;

// audio setup
float harmonics = 1.2;
float base_freq = 440.0;
int output_freq[waveNumber];
float depth = 0.25;

// input setup
#define timePot  A0
#define ratePot  A1
#define pitchPot A2
#define harmPot  A3
#define slider   A5

void setup(){
  // input & led pin initialization
  pinMode(timePot,  INPUT);
  pinMode(ratePot,  INPUT);
  pinMode(pitchPot, INPUT);
  pinMode(harmPot,  INPUT);
  pinMode(slider,   INPUT);

  for (int i = 0; i < waveNumber; i++) {
    waveGain[i] = 0;
  }
  waveGain[0] = 8;
  updateFreq();
  output_freq[0] = 440;
    
  ledPin[0] = 10;
  ledPin[1] = 11;
  ledPin[2] = 2;
  ledPin[3] = 3;
  ledPin[4] = 4;
  ledPin[5] = 5;
  ledPin[6] = 6;
  ledPin[7] = 7;
  ledPin[8] = 8;
  for (int i = 0; i < waveNumber; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  
  kVib.setFreq(6.5f);
  startMozzi(CONTROL_RATE);
}

void updateControl(){
  float vibrato = depth * kVib.next();
  aSin_1.setFreq(output_freq[0]);
  aSin_2.setFreq(output_freq[1]);
  aSin_3.setFreq(output_freq[2]);
  aSin_4.setFreq(output_freq[3]);
  aSin_5.setFreq(output_freq[4]);
  aSin_6.setFreq(output_freq[5]);
  aSin_7.setFreq(output_freq[6]);
  aSin_8.setFreq(output_freq[7]);
  aSin_9.setFreq(output_freq[8]);

  /* randomly turn on/off the different waves every XX milliseconds (?) */
  unsigned long currTime = millis();
  if (currTime - prevTime > interval){
    prevTime = currTime;
    randomSounds();
  }
}

int updateAudio(){
//  int soundResult = aSin_1.next() * waveGain[0]
//                   +aSin_2.next() * waveGain[1]
//                   +aSin_3.next() * waveGain[2]
//                   +aSin_4.next() * waveGain[3]
//                   +aSin_5.next() * waveGain[4]
//                   +aSin_6.next() * waveGain[5]
//                   +aSin_7.next() * waveGain[6]
//                   +aSin_8.next() * waveGain[7]
//                   +aSin_9.next() * waveGain[8];
  int soundResult = aSin_1.next();
  return (soundResult)>>8;
}

void loop(){
  audioHook();
}

void updateFreq(){
  int last_freq = base_freq;
  for (int i = 0; i < waveNumber; i++){
    output_freq[i] = (int) last_freq;
    last_freq *= harmonics;
  }
}

void randomSounds(){
  for (int i = 0; i < waveNumber; i++) {
    float aux = random(100);
    if (aux < occurrence){
//      waveGain[i] = 255;
      digitalWrite(ledPin[i], 0);
    } else {
//      waveGain[i] = 0;
      digitalWrite(ledPin[i], 1);
    }
  }
  normalizeGain();
}

void normalizeGain(){
  int totalGain = 0;
  for (int i = 0; i < waveNumber; i++){
    totalGain += waveGain[i];
  }
  for (int i = 0; i < waveNumber; i++){
    waveGain[i] = waveGain[i]/totalGain;
  }
}

