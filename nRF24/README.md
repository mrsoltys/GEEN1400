# nRF24 Wireless Communication

Many students are drawn to the nRF24 radios because they'e low cost, small, and have relitivly low power requirements. So I'm going to do a quick writeup on them here with some example code to get you started.

## Hooking up the Radios

[<img src="https://www.mysensors.org/uploads/57c1a2411730a6c715b6b1b0/image/nrfTop.png">](https://www.mysensors.org/)

The RF24 radios use the [SPI protocol](https://www.arduino.cc/en/reference/SPI) for communicating, which means on _most_ ardunios you *must use* pins 

 * 11 (`MOSI`) 
 * 12 (`MISO`)
 * 13 (`SCK`) 

 Luckly, you can share these pins with other SPI devices, so they're not completely used up by the radios. In additon, you have two additional pins that you can pick up, but you can use other digitial I/Os for them:

  * `CE` 
  * `CSN`

For the examples in this GitHub Repo, I hooked `CE` to 9 and `CSN` to 10, as shown in this hookup schematic: 
<img src="https://raw.githubusercontent.com/mrsoltys/GEEN1400/master/nRF24/radioHookup.png" width="400">

Three __important notes:__ 

 1) You need to power the radio with 3.3v (not 5v!)
 2) [Some hookup guides](https://www.mysensors.org/build/connect_radio) suggest using a 4.7µF to 47µF decoupling capacitor accorss power and ground. This doesn`t hurt, and seems to be a best pratice that could save you a headache down the line. Connect the + to 3.3v and the - to GND.
 3) I didn't use the `IRQ` pin... but it does enable some advanced functionality. If you have high traffic or are sending large amounts of data, you might wnat to read up on this.

## Coding Basics
You'll need to write separate scripts for the arduino that is transmitting data and the arduino that is recieving data. Some things they will have in common are:

 * Libraries. Both will use the `RF24` libary, which has some dependencies including `nRF24L01`, and `RF24_config`. Your header will look like:

        #include <nRF24L01.h>
        #include <RF24.h>
        #include <RF24_config.h>

 * Radio setup. The `CE` and `CSN` pins are adjustable, so you'll need to define the radio based on what pins these are connected to. Additionally, you'll need the address to match on all the radios you want able to talk to eachother. The value you pick for address is arbitrary, but if other people near you are also using these radios, be sure you have a different address than them.

        RF24 radio(9,10);
        const byte address[6]="00001";

 * In the `void setup()` function you'll need turn on the radio, and set the power level. [More on power savings below.](https://github.com/mrsoltys/GEEN1400/tree/master/nRF24#power-savings)

        radio.begin();
        radio.setPALevel(RF24_PA_MAX);

### Transmitting Data
In the `void setup()` you'll need to tell the radio that you'll be writing data (transmitting) and not to listen for incomming data:

       radio.openWritingPipe(address);
       radio.stopListening();

Then, in your `void loop()` you can transmit data using:

       radio.write()

### Recieving Data
In the `void setup()` you'll need to tell the radio that you'll be reading data (Recieving) and to start listening for incomming data:

       radio.openReadingPipe(address);
       radio.startpListening();

Then, in your `void loop()` you can tell if there's an incomming message using `if(radio.available())`. If there is datat to read, you can read it using:

       radio.read()


## Examples
Right now I have one example, a simple sketch for transmitting which contains a [button](https://github.com/mrsoltys/GEEN1400/tree/master/Buttons) connected to the transmitter device and an LED on the reciever device. Pushing the button on the transmitter device sends a 1, which signals the LED to turn on. Releasing the button sends a 0, which signals the LED to turn off.

## Power savings
In my examples, the power level is set to `RF24_PA_MAX`. I've heard of others having trouble with `RF24_PA_MIN`... although the 4.7µF decoupling capacitor might alleviate these problems. In the library, there are 4 power levels you can choose from:

 * `RF24_PA_MIN` 
 * `RF24_PA_LOW`
 * `RF24_PA_HIGH` 
 * `RF24_PA_MAX`

 My philosophy: _Go big or go home_. If you really want to save power, I'd recommend using the `radio.powerDown();` and `radio.powerUp();` functions defined in the library