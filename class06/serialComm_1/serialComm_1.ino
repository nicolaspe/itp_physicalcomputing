# define potPin A5
# define ledPin 3

void setup() {
  // initialize pins
  pinMode(ledPin, OUTPUT);
  // initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // read & print pot value
//  int potValue = analogRead(potPin);
//  Serial.println(potValue);

  // check if there's a message!
  if(Serial.available() > 0){
    // read, BYTE by BYTE! (char by char)
    int fromSerial = Serial.read();
    
    // to read AS A NUMBER
//    int fromSerial = Serial.parseInt();

    // print message
    Serial.println(fromSerial);
  }

  delay(10);
}

void blink(){
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

