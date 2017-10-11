#define lightSensor A0

int minValue = 1023;
int maxValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // value read
  int lightValue = analogRead(lightSensor);

  // calibrate min/max values
  if(lightValue < minValue) minValue = lightValue;
  if(lightValue > maxValue) maxValue = lightValue;

  // calibrated mapping
  int mappedValue = map(lightValue, minValue, maxValue, 0, 180);
  
  // print values
  Serial.println(mappedValue);
}
