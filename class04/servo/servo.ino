# include <Servo.h>
Servo myServo;

void setup() {
  // attach myServo to a pin
  myServo.attach(9);
}

void loop() {
  for(int i = 0; i<180; i++){
    myServo.write(i);
    delay(40);
  }
  for(int i = 180; i>0; i--){
    myServo.write(i);
    delay(40);
  }
//  myServo.write(120);
//  delay(500);
//  myServo.write(60);
//  delay(500);
}
