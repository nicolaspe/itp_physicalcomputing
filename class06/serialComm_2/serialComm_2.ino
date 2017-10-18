# define potPin A5
# define ledPin 3

void setup() {
  // initialize pins
  pinMode(ledPin, OUTPUT);
  // initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // read & print value
  int potValue = analogRead(potPin);
  Serial.println(potValue);

  delay(50);
}
