#include <Servo.h>
Servo myServo;

void setup() {
  myServo.attach(9);                 // attach myServo to pin 9
}

void loop() {
  sweepWithoutDelay()
}

const long sweepTime = 5000;          // How many seconds you'd like your servo to take to do one sweep back and fourth
unsigned long sweepStart = 0;         // Save the time you started the last sweep
void sweepWithoutDelay() {
  unsigned long currentSweep = millis() - sweepStart;
  if (currentSweep > sweepTime)
    sweepStart = millis();

  if (currentSweep < sweepTime / 2)
    myServo.write(map(currentSweep, 0, sweepTime / 2, 0, 180));
  else
    myServo.write(map(currentSweep, sweepTime / 2, sweepTime, 180, 0));
}