// Delays can keep your arduino from living up to it's full potential. 
// They pause the brain, when it in reality could be doing other useful things!
// This code lets you blink an LED, while doing other useful things in your void loop() function.

#define ledPin 13
void setup(){
  pinMode(ledPin,OUTPUT);
}

void loop(){
  // This will blink the LED
  blinkWithoutDelay();
  // You can do other stuff while the LED is blinking!
}

const long blinkInterval=1000;
unsigned long lastBlink=0;
bool ledState=LOW;

void blinkWithoutDelay() {
if (millis()-lastBlink>=blinkInterval) {
  //save the last time you Blinked the LED
  lastBlink=millis();

  //toggle the LED state
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  }
}