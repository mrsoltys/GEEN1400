#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define buttonPin 3  // INPUT Button for sending

bool ledState=LOW;

RF24 radio(9,10);
const byte address[6]="01100";

void setup() {
  pinMode(buttonPin,INPUT); 

  radio.begin();
  radio.setPALevel(RF24_PA_MAX);  

  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  if(digitalRead(buttonPin)==LOW && ledState==LOW){
    ledState=HIGH;
    byte dataOut=1;
    radio.write(&dataOut,sizeof(dataOut));
  }
  else if((digitalRead(buttonPin)==HIGH && ledState==HIGH)){
    ledState=LOW;
    byte dataOut=0;
    radio.write(&dataOut,sizeof(dataOut));
  }
}
