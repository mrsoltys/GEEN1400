Avoiding Delays
===============

Delays can keep your arduino from living up to its full potential! They pause the brain, when it in reality could be doing other useful things! These codes provide some examples to do some common functions like blinking a LED or sweeping a servo, without ever using the delay() function! This means they'll work, even if your arduino is doing other things!

Doing three things at once
------------------------
As an example, pretend you want to blink an LED and Sweep a servo. Traditionally, it'd be impossible to do both at once because your code would look like this:

    digitalRead(buttonPin); 		//check to see if the button is pressed

    //Blink the LED
    digitalWrite(ledPin,HIGH);
    delay(1000);					//Note: Your Processor isn't doing anything
    digitalWrite(ledPin,LOW);
    delay(1000);					//Note: Your Processor isn't doing anything

    //Sweep the servo
    for(pos = 0; pos < 180; pos += 1){
      myservo.write(pos);  
      delay(15);                   //Note: Your Processor isn't doing anything
    } 
    for(pos = 180; pos>=1; pos-=1){                                
      myservo.write(pos);           
      delay(15);                   //Note: Your Processor isn't doing anything
    } 

It takes a full 7 seconds for the LED to blink once, and then for the servo to sweep. (They happen one after the other, not at the same time). This means, if someone presses the button while these things are happening, it will miss it!

If we avoid delays, we can have the servo sweep while the LED blinks, and the processor will be free to also "listen" for button presses and do other actions as well. Our code could look like:

	digitalRead(buttonPin);
	blinkWithoutDelay();
	sweepWithoutDelay();
	// Do other stuff as well!

