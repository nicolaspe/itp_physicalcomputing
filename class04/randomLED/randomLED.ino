/* randomLED for Laser Harp project!
 *
 * by nicolás peña-escarpentier
 *
 * October, 2017 */


// laser & sensor setup
const int laserNumber = 9;
int laserPin[laserNumber];
int occurrence = 50;

// pots setup
# define bigPot A0
# define smlPot A1

// time keeping from
// http://www.makeuseof.com/tag/arduino-delay-function-shouldnt-use/
long prevTime = 0;
long interval = 100;

// led output for testing!
int ledPin[laserNumber];

void setup() {
  // laser pins declaration
  laserPin[0] = 2;
  laserPin[1] = 3;
  laserPin[2] = 4;
  laserPin[3] = 5;
  laserPin[4] = 6;
  laserPin[5] = 7;

  // output pin declaration
  for (int i = 0; i < laserNumber; i++) {
    pinMode(laserPin[i], OUTPUT);
  }

  // pots setup
  pinMode(bigPot, INPUT);
  pinMode(smlPot, INPUT);

  // Serial com
  Serial.begin(9600);
}

void loop() {
  /* analog info read */
  int bigVal = analogRead(bigPot)/10;
  int smlVal = analogRead(smlPot)/10;

  /* big pot to interval */
  interval = map(bigVal, 0, 102, 50, 220);

  /* small pot to occurrence rate */
  occurrence = map(smlVal, 0, 102, 20, 80);
  
  /* randomly turn on/off the lasers every XX milliseconds (?) */
  unsigned long currTime = millis();
  if (currTime - prevTime > interval){
    prevTime = currTime;
    // randomLasers();
    randomLasers();
  }
}

void randomLasers(){
  for (int i = 0; i < laserNumber; i++) {
    float aux = random(100);
    if (aux < occurrence){
      digitalWrite(laserPin[i], 0);
    } else {
      digitalWrite(laserPin[i], 1);
    }
  }
}

