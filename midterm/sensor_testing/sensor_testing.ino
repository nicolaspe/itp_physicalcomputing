/*
 * PIR sensor tester
 * from https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/using-a-pir
 */
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);
  
  // check if the input is HIGH
  if (val == HIGH) {
    // turn LED ON
    digitalWrite(ledPin, HIGH);

    // We only want to print on the output change, not state
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    // turn LED OFF
    digitalWrite(ledPin, LOW); 
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
