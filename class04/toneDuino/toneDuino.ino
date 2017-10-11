// EXTERNAL FILES
# include "pitches.h"

// INPUT
# define potPin A0
# define butPin 3
// OUTPUT
# define speak1 9

void setup() {
  // define pin modes
  pinMode(potPin, INPUT);

  // Serial communication
  Serial.begin(9600);
}

void loop() {
  // read and button potentiometer value (0-1023)
  int butValue = digitalRead(butPin);
  int potValue = analogRead(potPin);

  // check button to play tone
  if(butValue == 1){
    // calculate and write tone frequency!
    int freq1 = map(potValue, 0, 1023, 200, 1200);
    tone(speak1, freq1);
  } else {
    noTone(9);
  }
}
