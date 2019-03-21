//Include Libraries
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Set Up Radios
RF24 radio(9,10);               //Mine is connected to pins 9 and 10
const byte address[6]="01100";  //Must be the same between transmit and recieve Arduino

//Define Input Button Pin
#define buttonPin 3 
bool ledState=LOW;

void setup() {
  pinMode(buttonPin,INPUT); 

  radio.begin();
  radio.setPALevel(RF24_PA_MAX);  

  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop() {
  // If button is pressed and LED is off
  if(digitalRead(buttonPin)==LOW && ledState==LOW){
    ledState=HIGH;
    bool dataOut=1; //set data to send to 1
    radio.write(&dataOut,sizeof(dataOut)); //send data
  }
  // If button is released and LED is on
  else if((digitalRead(buttonPin)==HIGH && ledState==HIGH)){
    ledState=LOW;
    bool dataOut=0; //set data to send to 0
    radio.write(&dataOut,sizeof(dataOut)); //send data
  }
}
