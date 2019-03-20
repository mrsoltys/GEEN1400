#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define ledPin 2

RF24 radio(9,10);
const byte address[6]="01100";

struct package
{
  int id = 0;
  int dirr = 0; //if 1, move forward
  //if 2, move backward
  //if 0, stay stationary
  char  text[10] = "";
};

typedef struct package Package;
Package dataIn;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
    
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  
  radio.openReadingPipe(0,address);
  radio.startListening();
}

void loop() {
  if(radio.available()){
 
    radio.read(&dataIn,sizeof(dataIn));
    Serial.println(dataIn.id);
    Serial.println(dataIn.dirr);
    Serial.println(dataIn.text);
    digitalWrite(ledPin,dataIn.id);
    }

}
