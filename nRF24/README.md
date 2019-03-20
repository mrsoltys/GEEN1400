# nRF24 Wireless Communication

Many students are drawn to the nRF24 radios because they're low cost, small, and have relitivly low power requirements. So I'm going to do a quick writeup on them here with some example code to get you started.

## Hooking up the Radios

[<img src="https://www.mysensors.org/uploads/57c1a2411730a6c715b6b1b0/image/nrfTop.png">](https://www.mysensors.org/)

The RF24 radios use the [SPI protocol](https://www.arduino.cc/en/reference/SPI) for communicating, which means on _most_ ardunios you *must use* pins 

 * 11 (MOSI) 
 * 12 (MISO)
 * 13 (SCK) 

 Luckly, you can share these pins with other SPI devices, so they're not completely used up by the radios. In additon, you have two additional pins that you can pick up, but you can use other digitial I/Os for them:

  * CE 
  * CSN

For the examples in this GitHub Repo, I'll be using this hookup schematic: 
<img src="https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/nRF24/radioHookup.png" width="400">

The only important note here is [some hookup guides](https://www.mysensors.org/build/connect_radio) suggest using a 4.7µF to 47µF decoupling capacitor accorss power and ground. This doesn't hurt, and seems to be a best pratice that could save you a headache down the line.