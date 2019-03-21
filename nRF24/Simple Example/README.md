# Simple RF24 Test Circuit

This simple test circuit has two arduinos (In the schematic below I'm using two Arduino Nano, because they're one of my favorite Arduinos). The transmit Circuit has has a button, and the recieve circuit has an LED. When the button is pressed, the transmit circuit sends **1** and the recieve circuit turns on the LED.  When the button is released, the transmit circuit sends **0** and the recieve circuit turns off the LED.

<img src="https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/nRF24/Simple Example/simple2RadioHookup.png" width="400">

Note: the data type used in transmit and recieve must match. Here, I'm sending a `bool`, which can be `1` or `0`, `TRUE` or `FALSE`, `HIGH` or `LOW`. `bool` is one of the smallest data types available in arduino, so should be one of the easiest to send and recieve. [Sparkfun has a nice (really in depth) tutorial on data types if you're interested in reading more.](https://learn.sparkfun.com/tutorials/data-types-in-arduino/all)