// INPUT
# define rotary A0
// OUTPUT
# define led1 9

void setup() {
  // define pin modes
  pinMode(rotary, INPUT);
  pinMode(led1, OUTPUT);

  // Serial communication
  Serial.begin(9600);
}

void loop() {
  // read rotary value (0-1023)
  int rotValue = analogRead(rotary);
  //Serial.println(rotValue);

  // calculate and write LED intensity (PWM)
  int intensity = map(rotValue, 0, 1023, 0, 255);
  analogWrite(led1, intensity);
}
