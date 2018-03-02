// Simple Button Example
// This code lights up an LED on Pin 13 
// when a button (connected to Pin 2) is pressed.
// The LED turns off when the button is released.
// This assumes you have an Input-Pullup resistor

#define buttonPin 2						//Button on Pin 2
#define ledPin 13						//LED on Pin 13

void setup(){
	pinMode(ledPin,OUTPUT);				//Set ledPin to Output
	pinMode(buttonPin,INPUT);			//Set buttonPin to InPut
}

void loop(){
	if(digitalRead(buttonPin)==LOW){	//The Button was pressed
		digitalWrite(ledPin,HIGH);		//Turn on the LED
	}
	else{								//The Button is not pressed
		digitalWrite(ledPin,LOW);		//Turn off the LED
	}
}