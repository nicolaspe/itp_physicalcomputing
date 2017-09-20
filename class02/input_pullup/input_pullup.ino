#define buttPin 2
#define gLED 3
#define bLED 4

int buttState;
int lightState = 0;

void setup() {
  pinMode(buttPin, INPUT_PULLUP);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int prevState = buttState;
  buttState = digitalRead(buttPin);
  Serial.print("The state of the button is: ");
  Serial.println(buttState);

  if(buttState == 1 && lightState == 0){
    digitalWrite(gLED, 1);
    digitalWrite(bLED, 1);
    lightState = 1;
  } else if(buttState == 1 && lightState == 1) {
    digitalWrite(gLED, 0);
    digitalWrite(bLED, 0);
    lightState = 0;
  }
}
