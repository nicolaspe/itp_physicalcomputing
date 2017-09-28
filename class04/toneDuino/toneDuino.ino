// EXTERNAL FILES
# include "pitches.h"

// INPUT
# define rotary A0
// OUTPUT
# define speak1 9
# define speak2 10 

void setup() {
  // define pin modes
  pinMode(rotary, INPUT);

  // Serial communication
  Serial.begin(9600);
}

void loop() {
  // read rotary value (0-1023)
  int rotValue = analogRead(rotary);

  // calculate and write tone frequency!
  int freq1 = map(rotValue, 0, 1023, 200, 1200);
  int freq2 = freq1*2;
//  tone(speak1, freq1);
  tone(speak2, freq2);

  delay(250);  
}
