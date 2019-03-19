#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define buttonPin 3  // INPUT Button for sending
#define ledPin 2     // OUTPUT led for debugging

bool ledState=LOW;

RF24 radio(9,10);
const byte address[6]="01100";

void setup() {
  pinMode(ledPin,OUTPUT); 
  pinMode(buttonPin,INPUT); 

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}

void loop() {
  if(digitalRead(buttonPin)==LOW && ledState==LOW){
    ledState=HIGH;
    const char text[]="1";
    radio.write(&text,sizeof(text));
  }
  else if((digitalRead(buttonPin)==HIGH && ledState==HIGH)){
    ledState=LOW;
    const char text[]="0";
    radio.write(&text,sizeof(text));
  }

  digitalWrite(ledPin,ledState);
}
