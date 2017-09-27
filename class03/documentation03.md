# Energy saving is important, but living is more important

This assignment prompts us to use both digital and analog inputs for a physical thing that does other things with the help of a microcontroller (yet another thing that does tons of things).

As I've been really into lights these days, and due to the impending ecosystem-based doom of our society, I introduced a photo resistor (fancy way of saying light-sensor) to turn them on only if it's dark outside.

```
void goRight(){
  // select corresponding LED to turn on
  switch(currentLED){
    case 0:
      digitalWrite(led4, 1);
      break;
    case 1:
      digitalWrite(led3, 1);
      break;
    case 2:
      digitalWrite(led2, 1);
      break;
    case 3:
      digitalWrite(led1, 1);
      break;
  }
  // go to next LED and prevent overflow
  currentLED = (currentLED+1)%4;
}
```
