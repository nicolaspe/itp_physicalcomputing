// INPUT
# define rButton 2 
# define lButton 3
# define sensor A0

// OUTPUT
# define led1 5   // rightmost LED
# define led2 6   // center-right LED
# define led3 9   // center-left LED
# define led4 10  // leftmost LED

// CONTROL VARIABLES
int timeDelay = 100;  // ms
int currentLED = 0;   // initialization
boolean rTurn = false;  // right turn
boolean lTurn = false;  // left turn
int turnRep = 0;      // turn signal repetitions

void setup() {
  // I/O inizialization
  pinMode(rButton, INPUT);
  pinMode(lButton, INPUT);
  pinMode(sensor,  INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600);   // console ini
}

void loop() {
  // read input values
  int rInput = digitalRead(rButton);
  int lInput = digitalRead(lButton);
  int nightCheck = analogRead(sensor);
  
  // verify turn signals
  if(rInput == 1){
    rTurn = true;
    lTurn = false;
    turnRep = 0;
    //Serial.println("RIGHT");
  } else if(lInput == 1){
    lTurn = true;
    rTurn = false;
    turnRep = 0;
    //Serial.println("LEFT");
  }

  // turn signal or turn on/off leds
  if(rTurn){
    goRight();
    turnRep++;
  } else if(lTurn){
    goLeft();
    turnRep++;
  } else if(nightCheck <= 300){ // if it's dark, turn LEDs on
    ledsOn();
  } else if(nightCheck > 300){
    ledsOff();
  }
  //Serial.println(nightCheck);
  
  // check signal stop
  if(turnRep >= 4*10){
    rTurn = false;
    lTurn = false;
    ledsOff();
  }

  // delay for next light/signal
  delay(timeDelay);
}

void goRight(){
  // turn off all the LEDs
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
  // select corresponding LED to turn on
  switch(currentLED){
    case 0:
      digitalWrite(led4, 1);
      break;
    case 1:
      digitalWrite(led3, 1);
      break;
    case 2:
      digitalWrite(led2, 1);
      break;
    case 3:
      digitalWrite(led1, 1);
      break;
  }
  // go to next LED and prevent overflow
  currentLED = (currentLED+1)%4;
}
void goLeft(){
  // turn off all the LEDs
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
  // select corresponding LED to turn on
  switch(currentLED){
    case 0:
      digitalWrite(led1, 1);
      break;
    case 1:
      digitalWrite(led2, 1);
      break;
    case 2:
      digitalWrite(led3, 1);
      break;
    case 3:
      digitalWrite(led4, 1);
      break;
  }
  // go to next LED and prevent overflow
  currentLED = (currentLED+1)%4;
}
void ledsOff(){
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
}
void ledsOn(){
  digitalWrite(led1, 1);
  digitalWrite(led2, 2);
  digitalWrite(led3, 3);
  digitalWrite(led4, 4);
}
