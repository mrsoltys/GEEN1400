LOTS OF LEDS!
=============

LEDs are so bright and shiny, so of course you'll want to use A LOT of them. 

LEDs in Series
--------------

One of the easiest ways to get lots of LEDs is to wire them in series. Becasue your Arduino outputs *5V*, you'll be limited by the _voltage drop_ across each LED. Most LEDs will have a _Forward Voltage Drop_ somewhere between 1.8V and 2.2V.  This means that 2 LEDs will require ~4V to run, and 3 LEDs will require ~6V (More than your 5V Arduino can supply). So for each 5V output pin, you can run 2 LEDs in series. 

<img src="https://github.com/mrsoltys/GEEN1400/blob/master/Lots%20of%20LEDs/Series1.png?raw=true" width="400">

You could use an external 9V power supply, which would get you up to about 4 LEDs, but we want more LEDs...

<img src="https://github.com/mrsoltys/GEEN1400/blob/master/Lots%20of%20LEDs/Series2.png?raw=true" width="400">

LEDs in Parallel 
----------------

In Parallel, we're limited by current instead of voltage. Each LED has the same voltage potential (5v on each Digital Output Pin); however, your Arduino is limited to outputing 40 mA per pin. Because each LED uses about 20 mA, you're still going to be limited to about 2 LEDs in parallel. If you hook up more than this, at best your LEDs will run dimmer than you'd expect, and at the worst you will damage your Arduino. 

<img src="https://github.com/mrsoltys/GEEN1400/blob/master/Lots%20of%20LEDs/Parallel%201.png?raw=true" width="400">

Going to our 9V external power supply, you can check it's rating to see how many LEDs it can run. Many batteries can provide 1 Amp, which would total (1 [A] / 20 [mA/LED])=50 LEDs in parellel. 

<img src="https://github.com/mrsoltys/GEEN1400/blob/master/Lots%20of%20LEDs/Parallel2.png?raw=true" width="400">

Note: This is a pretty boring circuit, because you can't flash them on and off. 

Controlling LEDs Powered by an external Power Supply
----------------------------------------------

We've seen how limited the power supply built into an Arduino is. To get around this, we can power our LEDs off an external power supply (like a 9V battery), but still control them using our 5V output pins. To do this we'll need to use a transistor, which acts as a switch or a bridge between the 5V arduino system and the 9V Battery system.

<img src="https://github.com/mrsoltys/GEEN1400/blob/master/Lots%20of%20LEDs/Transistor.png?raw=true" width="400">

This is a really powerful tool to have in your back pocket when working with anything that might draw a lot of current or requires a higher voltage (LEDs, motors, almost anything!)

Controlling more LEDs
---------------------

What is the maximum number of LEDs you can individually control from your Arduino? You might be tempted to say 14 because you have 14 Digital I/O pins.

But actually, you can use your analog input pins as digital output pins as well! 

	digitalWrite(A0,High);

What if you want more?  Well you can multiply pins using some advanced techniques including:
 * [Individually adressable LEDs](https://learn.adafruit.com/adafruit-neopixel-uberguide) (The WS2812b's are my favorite)
 * [Shift Registers](https://bildr.org/2011/02/74hc595/)
 * [Multiplexing](https://appelsiini.net/2011/how-does-led-matrix-work/)



 Based on these techniques, you can control a virtually unlmited number of LEDs from your board!

 Calculating Resistors
 ---------------------

Note: Using multiple LEDs will change the resistor value you'll need. [I use this calculator](http://ledcalc.com/#calc) to determine the correct current limiting resistor based on the LEDs I'm using. Before you hook up 2 LEDs on each of your 14 Digital Output pins (28 LEDs total), Please note that the Arduino can supply a maximum of about 200 mA of power, regardless of how you hook the LEDs to it. This means you can hook up about 10 LEDs to a single Arduino before you start asking for trouble. 