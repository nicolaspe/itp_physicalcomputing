// see http://www.instructables.com/id/How-to-Use-an-RGB-LED/

// INPUT
# define rotary A0
// OUTPUT
# define controlLED 9
# define rPin 3
# define gPin 5
# define bPin 6

void setup() {
  // define pin modes
  pinMode(rotary, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(controlLED, OUTPUT);

  // Serial communication
  Serial.begin(9600);

  // color Mode
  colorMode(HSB, 360, 100, 100);
}

void loop() {
  int potValue = analogRead(rotary);
  //Serial.println(rotValue);

  // calculate and write control led
  int intensity = map(potValue, 0, 1023, 0, 255);
  analogWrite(controlLED, intensity);

  // get hue and calculate each channel
  int hue = map(rotValue, 0, 1023, 0, 359);
  color ledColor = color(hue, 100, 100);
  int rVal = red(ledColor);
  int gVal = green(ledColor);
  int bVal = blue(ledColor);

  // write values to get desired color
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}

int[] huetorgb(int h, int b){
}
}

