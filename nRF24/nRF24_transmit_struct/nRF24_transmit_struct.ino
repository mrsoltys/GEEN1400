#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define buttonPin 3  // INPUT Button for sending

bool ledState=LOW;

RF24 radio(9,10);
const byte address[6]="01100";

struct package
{
  int id = 1;
  int dirr = 1; //if 1, move forward
  //if 2, move backward
  //if 0, stay stationary
  char  text[10] = "move";
};

typedef struct package Package;
Package data;

void setup() {
  pinMode(buttonPin,INPUT); 

  radio.begin();
  radio.setPALevel(RF24_PA_MAX);  

  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  radio.write(&data, sizeof(data));
  delay(1000);
}
