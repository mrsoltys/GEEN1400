// Button interrupt Example
// This code toggles an LED on Pin 13 on or off
// when a button (connected to Pin 2) is pressed.
// This assumes you have an Input-Pullup resistor


#define buttonPin 2						//Button on Pin 2
#define ledPin 13						//LED on Pin 13

volatile bool ledState=LOW;				//this variable saves if the LED is on or off

void setup(){
	pinMode(ledPin,OUTPUT);				//Set ledPin to Output
	pinMode(buttonPin,INPUT);			//Set buttonPin to InPut

	//Make buttonPin an interrupt.
	//Call the function changeLedState()
	//When the button goes from HIGH to LOW (FALLING)
	attachInterrupt(digitalPinToInterrupt(buttonPin), changeLedState, FALLING);
}

void changeLedState(){
	ledState = !ledState;				//the ! toggles the ledState from HIGH to LOW or visa versa
}

void loop(){
	digitalWrite(ledPin,ledState);		//We just need to set the LED to ledState. 
										//we don't ahve to check for the button, The interrupt will take care of that.
}