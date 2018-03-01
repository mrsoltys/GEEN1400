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
### Using digitalRead()

The easy way to check if a button is pressed is using `digitalRead()`. In all of my examples, if `digitalRead(buttonPin)==LOW` the button is pressed, and if `digitalRead(buttonPin)==HIGH` the button _is not_ pressed.  This is because both of my example hookups use _pull-up resistors_ (either external or internal).

This is counter-intuitive for most engineers, so I'll reiterate:

| Button State | `digitalRead()` | 
| :-----------:|:---------------:|
| Button **IS** pressed | LOW  |
| Button **IS NOT** pressed | HIGH | 

It's important to note that it can be easy for the Arduino to miss a button press using `digitalRead()` if there are other things going on. Take this example:
     
     void loop(){
     	digitalRead(buttonPin);
     	delay(10000)
     }

The microcontroller is checking for the button press for 1 ms every 10 seocnds. that means if I push the button and release it during the `delay()`, the microcontroller will never know I pushed the button. For this code to work properly, the user will have to hold the button down, on average, for 5 seconds until the controller recognizes the button is pressed. You can solve this problem by: 

 * [avoiding delays](https://github.com/mrsoltys/GEEN1400/tree/master/Avoiding%20Delays) 
 * setting your button up as in Interrupt, as discussed in the next section.

### As an Interrupt (Advanced, but very useful)

Pins 2 and 3 on the Arduino can be set up to "Interrupt" the code. This means the code will pause, do a specific action, and then resume where it left off.

The wiring of the button is the same, you can either use a pullup resistor (use `pinMode(buttonPin,INPUT)`), or the internal pullup on the Arduino board (use `pinMode(buttonPin,INPUT_PULLUP)`). _I reccomend a pullup resistor._

Then, you can set the arduino to use the pin as an interrupt like this:

    void setup() {
      pinMode(buttonPin, INPUT);
      attachInterrupt(digitalPinToInterrupt(buttonPin), ISR, LOW);
    }

    void ISR(){
    	\\Do Something when the button is pressed.
    }

 **Notes:**
 
   * The last term, `LOW` is the state that will trigger the intterrupt. `LOW` means _when the button is pressed_. You can also try

     * `CHANGE` - When the button state changes from `HIGH` to `LOW` or visa versa
     * `FALLING` - When the button state chagnes from `HIGH` to `LOW` only. (When the button is being pressed)
     * `RISING` - When the button state chagnes from `LOW` to `HIGH` only. (When the button is being pressed)
     * `HIGH` - When the button _is not_ pressed. 
   * `ISR` is a _function_ to call when the button is pressed. You can call it whatever you want (it does not need to be called `ISR()`). E.g.,  you could call the function blink: `attachInterrupt(digitalPinToInterrupt(buttonPin), blink, LOW);` and then the function the interrupt would look for would be `void blink()`
   * _Warning:_ The function you call should be very short and quick (a couple of lines max), and not contain loops or delays. The function also has to be of type `void` and can't take any inputs.
   * _Warning:_ Any variables you need to access in the interrupt function need to be _global_ (i.e., defined _above_ `void setup()`) and should be proceeded with the keyword `volatile`. 

   
   # FAQ
   
    * **Q: Why Not use a pull-down resistor?**
      * A: If you know what you're doing, a pull-down resistor can be fine. The main problem I've had with a pull-down resistor is if the button is connected with a long piece of wire to the Arduino, the wire can act as an antenna and possibly trigger erroneously. I haven't had this problem with a pull-up resistor, so I always use them. Also, I went down a rabbit-hole once trying to understand which uses _less_ power and my answer was, suprisingly, that a pull-up resistor uses _slightly_ less power than a pull-down. 



