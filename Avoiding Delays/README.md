# Avoiding Delays


Delays can keep your arduino from living up to its full potential. They pause the "brain," when it could be doing other useful things! In this folder are some examples that do common things without ever using `delay()`

 * [Blink an LED](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/blinkWithoutDelay.ino)
 * [Sweep a Servo](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/sweepWithoutDelay.ino)

You'll notice they operate using the `millis()` command which returns the current time (in milliseconds) since the Arduino was powered on. Instead of using a delay, we save the time an action started (like the servo begins sweeping or the LED turns on), and the compare the current time, `millis()`, to the previous time. 

### Example: Doing three things at once

As an example, pretend you want to blink an LED and Sweep a servo, all while listening for a button press. Traditionally, it'd be impossible to do all three at once because your code would look like this:

	
    digitalRead(buttonPin);       //check to see if the button is pressed

    //Blink the LED
    digitalWrite(ledPin,HIGH);    //Turn the LED On
    delay(1000);				          //PROCESSOR ISN'T DOING ANYTHING
    digitalWrite(ledPin,LOW);     //Turn the LED Off
    delay(1000);				          //PROCESSOR ISN'T DOING ANYTHING

    for(pos = 0; pos < 180; pos += 1){  //sweep from 0 to 180
      myservo.write(pos);  
      delay(15);                  //PROCESSOR ISN'T DOING ANYTHING (x180)
    } 
    for(pos = 180; pos>=1; pos-=1){     //sweep from 180 to 0
      myservo.write(pos);           
      delay(15);                  //PROCESSOR ISN'T DOING ANYTHING (x180)
    } 

It takes **2 seconds** for the LED to blink once, and then **5.4 seconds** for the servo to sweep. Even worse, they happen one after the other, not at the same time. This means, if someone presses the button during the 7.4 seconds while other things are happening, _your Arduino will miss it_!

If we avoid delays, we can have the servo sweep _while_ the LED blinks, and the processor will be free to also "listen" for button presses and do other actions as well. Our code could look like:

	digitalRead(buttonPin);
	blinkWithoutDelay();
	sweepWithoutDelay();
	// Do other stuff as well!

Check out the functions [`blinkWithoutDelay()`](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/blinkWithoutDelay.ino) and [`sweepWithoutDelay()`](https://github.com/mrsoltys/GEEN1400/blob/master/Avoiding%20Delays/sweepWithoutDelay.ino) in the examples. They're not built into Arduino.

## Button Interrupts 
For even better performance for your buttons, even with delays, check out the tutorial on button interrupts!