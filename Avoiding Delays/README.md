# Avoiding Delays


Delays can keep your arduino from living up to its full potential! They pause the "brain," when it could be doing other useful things! In this folder are some example codes that do common things without ever using `delay()`

 * [Blink an LED](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/blinkWithoutDelay.ino)
 * [Sweep a Servo](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/sweepWithoutDelay.ino)

You'll notice they all operate using the `millis()` command which returns the current time (in milliseconds) since the Arduino was powered on. Instead of using a delay, we save the time an action started (like the servo begins sweeping or the LED turns on), and the compare the current time, `millis()`, to the previous time. 

### Example: Doing three things at once

As an example, pretend you want to blink an LED and Sweep a servo, all while listening for a button press. Traditionally, it'd be impossible to do both at once because your code would look like this:

	//check to see if the button is pressed
    digitalRead(buttonPin); 	

    //Blink the LED
    digitalWrite(ledPin,HIGH);
    delay(1000);				//Note: Your Processor isn't doing anything
    digitalWrite(ledPin,LOW);
    delay(1000);				//Note: Your Processor isn't doing anything

    //Sweep the servo
    for(pos = 0; pos < 180; pos += 1){
      myservo.write(pos);  
      delay(15);                //Note: Your Processor isn't doing anything
    } 
    for(pos = 180; pos>=1; pos-=1){                                
      myservo.write(pos);           
      delay(15);                //Note: Your Processor isn't doing anything
    } 

It takes a full *7 seconds* for the LED to blink once, and then for the servo to sweep. (They happen one after the other, not at the same time). This means, if someone presses the button while these things are happening, your Arduino will miss it!


If we avoid delays, we can have the servo sweep _while_ the LED blinks, and the processor will be free to also "listen" for button presses and do other actions as well. Our code could look like:

	digitalRead(buttonPin);
	blinkWithoutDelay();
	sweepWithoutDelay();
	// Do other stuff as well!

check out the functions `blinkWithoutDelay()` and `sweepWithoutDelay()` up top!

## Button Interrupts 
For even better performance for your buttons, even with delays, check out the tutorial on button interrupts!