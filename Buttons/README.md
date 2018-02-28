Using Buttons
=============

Buttons seem like the simplest sensor, and that can often lull you to think they'll be the easiest to hook up; however, an improperly connected button will behave erratically and give you a lot of headaches. 

Hooking up a button
===================
Using a Pull-Up resistor (recommended)
--------------------------------------
The recommended method to attach a button is using a "pullup resistor." The best resistor to use for this is a 10kΩ.

![](https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/Buttons/ButtonInputPullupResistor_bb.png)
	
	 #define buttonPin 2
     void setup(){
     	pinMode(buttonPin,INPUT);
     }

     void loop(){
     	if(digitalRead(buttonPin)==LOW)
     		//The button was pressed
     }

Using the internal pullup resistor
----------------------------------
Alternitvly, the microcontroller has in internal resistor built in. This circuit does not need an external resistor.

![](https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/Buttons/ButtonInternalPullup_bb.png)

To activate the internal resistor you need to use `INPUT_PULLUP` in the `setup()` function:

	 #define buttonPin 2
     void setup(){
     	pinMode(buttonPin,INPUT_PULLUP);
     }

     void loop(){
     	if(digitalRead(buttonPin)==LOW)
     		//The button was pressed
     }


Coding the button
=================
Using digitalRead()
-------------------

As an interrupt (Advanced, but very useful)
-----------------------------------------