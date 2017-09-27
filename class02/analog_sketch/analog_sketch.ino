# define butPin 2
# define ledPin 4
# define logPin A2

void setup() {
  pinMode(butPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(logPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonVal = digitalRead(butPin);
  int analogVal = analogRead(logPin);
  if(buttonVal == 1){
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }
  Serial.println(analogVal);
//  delay(100);
}
