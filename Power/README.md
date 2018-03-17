
<img src="https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/Power/Arduino Voltage Supply.png" width="400">

# Powering your Arduino

It is important to only power your arduino using one of the following options. Powering your Arduino from mulitple sources (e.g., the barrel jack _and_ the VIN pin can lead to unexpected complications and potentially ruin your Arduino)
  * **USB Port (5 V)** This can be connected to the USB port of your computer, or a USB phone charger. Per USB standards, this expects a 5V input (Not more, not less). The Arduino should limit the current draw on the USB port to 500 mA
  * **Barrel Jack (7-12 V)** This can be hooked up to a wall-wart power supply, or to a battery with a barrel jack connector. 
  * **VIN pin (6-12 V)** This is less protected than input from the barrel jack, but can be driven from lower power.  
    * Alternatively, you can also use the VIN pin as an output voltage, and it will deliver the same voltage that comes from the barrel jack. This is useful if you have components that need to draw 12 V.
  * **5 V pin (5 V)** Just because you _can_ power the Arduino from the 5V pin, doesn't mean you should. This is only acceptable if you have a clean, regulated, 5V power supply. This pin offers _the least_ protection and inputting power here is an easy way to ruin your microcontroller.

## Recommended Input Voltage

  This really depends on your project. If you have components that operate on 12V, you may consider using a 12V power supply to provide power to your Arduino and these components. If not, I'd recommend the smallest Voltage you can get away with, as less heat is lossed in the regulator (and because of this, the regular is safe to provide more current).  7V into the barrel jack or 6V into VIN are both good options.