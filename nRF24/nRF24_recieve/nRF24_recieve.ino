#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(9,10);
const byte address[6]="01100";
void setup() {
  // put your setup code here, to run once:
  radio.begin();
  Serial.begin(9600);
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if(radio.available()){
    char text[32]="";
    radio.read(&text,sizeof(text));
    Serial.println(text);
    }

}
