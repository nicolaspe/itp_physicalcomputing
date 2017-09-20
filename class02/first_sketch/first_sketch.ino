// defining my LEDs
#define gLED 3
#define bLED 4

int t = 200;

void setup() {
//  pinMode(2, INPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void loop() {
  digitalWrite(gLED, 1);
  digitalWrite(bLED, 1);
  delay(1000);
  digitalWrite(gLED, 0);
  delay(1000);
  digitalWrite(gLED, 1);
  delay(500);
  digitalWrite(bLED, 0);
  delay(500); 
  digitalWrite(gLED, 1);
  delay(1000);
  digitalWrite(gLED, 1);
}
