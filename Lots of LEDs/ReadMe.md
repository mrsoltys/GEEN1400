LOTS OF LEDS!
=============

LEDs are so bright and shiny, so of course you'll want to use A LOT of them. 

LEDs in Series
--------------

One of the easiest ways to get lots of LEDs is to wire them in series. Becasue your Arduino outputs *5V*, you'll be limited by the _voltage drop_ across each LED. Most LEDs will have a _Forward Voltage Drop_ somewhere between 1.8V and 2.2V.  This means that 2 LEDs will require ~4V to run, and 3 LEDs will require about 6V to run (More than your Arduino can supply). So for each output pin, you can run 2 LEDs in series. 


*NEED SCHEMATIC*

You could use an external 12V power supply, which would get you up to about 6 LEDs, but we want more LEDs...

Note: Using multiple LEDs in series will change the resistor value you'll need. [I use this calculator](http://ledcalc.com/#calc) to determine the correct current limiting resistor based on the LEDs I'm using. Before you hook up 2 LEDs on each of your 14 Digital Output pins (28 LEDs total), Please read below about maximum current.

LEDs in Parallel 
----------------

In Parallel, we're limited by current instead of voltage. Each LED has the same voltage potential (5v on each Digital Output Pin); however, your Arduino is limited to outputing 40 mA per pin. Because each LED uses about 20 mA, you're still going to be limited to about 2 LEDs in parallel. If you hook up more than this, at best your LEDs will run dimmer than you'd expect, and at the worst you will damage your Arduino. 

*Need Schematic*

Going to our 12 V external power supply, you can check it's rating to see how many LEDs it can run. Many power supplies can run 3+ Amps, which would total (3 [A] / 20 [mA/LED])=150 LEDs in parellel. 

*Need Schematic*

Note: This is a pretty boring circuit, because you can't flash them on and off. 
