/* laserTests for Laser Harp project!
 *
 * by nicolás peña-escarpentier
 *
 * October, 2017 */

// libraries
#include <MozziGuts.h>

// laser & sensor setup
const int laserNumber = 9;
int laserPin[laserNumber];
int sensorPin[laserNumber];
int sensorValues[laserNumber];
int threshold = 200;

// time keeping from http://www.makeuseof.com/tag/arduino-delay-function-shouldnt-use/
long prevTime = 0;
long interval = 20;

// led output for testing!
int ledPin[laserNumber];

void setup() {
  // laser pins declaration
  laserPin[0] = 0;
  laserPin[1] = 0;
  laserPin[2] = 0;
  laserPin[3] = 0;
  laserPin[4] = 0;
  laserPin[5] = 0;
  laserPin[6] = 0;
  laserPin[7] = 0;
  laserPin[8] = 0;

  // output pin declaration
  for (int i = 0; i < laserNumber; i++) {
    pinMode(laserPin[i], OUTPUT);
  }

  // sensor pins declaration
  sensorPin[0] = A0;
  sensorPin[1] = A0;
  sensorPin[2] = A0;
  sensorPin[3] = A0;
  sensorPin[4] = A0;
  sensorPin[5] = A0;
  sensorPin[6] = A0;
  sensorPin[7] = A0;
  sensorPin[8] = A0;
}

void loop() {
  /* randomly turn on/off the lasers every XX milliseconds (?) */
  unsigned long currTime = millis();
  if (currTime - prevTime > interval){
    prevTime = currTime;
    // randomLasers();
    randomLasersTEST(sensorValues);
  }

  /* read every sensor pin */
  // DISABLED FOR TEST
  // readPins(sensorValues);

  /* if the value is higher than the threshold (light on), play a tone */
  for (int i = 0; i < laserNumber; i++) {
    // LED TEST OUTPUT
    if (sensorValues[i] > threshold) {
      digiwalWrite(ledPin[i], 1);
    } else {
      digitalWrite(ledPin[i], 0);
    }

  }
}

void randomLasers(){
  for (int i = 0; i < laserNumber; i++) {
    float aux = random();
    if (aux < 0.5){
      digitalWrite(laserPin[i], 0);
    } else {
      digitalWrite(laserPin[i], 1);
    }
  }
}
void readPins(int values[]){
  for (int i = 0; i < laserNumber; i++) {
    values[i] = analogRead(sensorPin[i]);
  }
}

// test function
void randomLasersTEST(int values[]){
  for (int i = 0; i < laserNumber; i++) {
    float aux = random(100);
    if (aux < 50){
      digitalWrite(laserPin[i], 0);
      values[i] = 800;
    } else {
      digitalWrite(laserPin[i], 1);
      values[i] = 0;
    }
  }
}
