Choosing Microcontrollers
=========================
The Sparkfun Redboard included in your 1400 kit is a good place to start for many projects, but as you require more input/output pins, or want to include advanced features like wifi, or reduce size, you might want to switch to a different arduino-compatiable microcontroller. Here are a few options that I've used in this course.

*NOTE: If you're looking for more Digital Pins, please know that all analog pins can be used as digital I/O*


| First Header       |  Notes | Price | Digital I/O pins                       | Memory     | Speed |
| -------------      | ------------- | ---------------------                  |-------     | -------     |  -------     |       
| Sparkfun Redboard  |  <ul><li>Great for Prototyping</li><li>Robust power supply and protection options</li><li>large size</li></ul> |$19.95  |  <ul><li>14 Digital I/O (6 PWM)</li><li>6 analog input</li></ul> | 32kb Flash | 16MHz |
| Arduino Nano       |  <ul><li>Great library compatability</li><li>small size</li><li>Careful with power inputs</li><li>Note: Not the same as Nano Every. Avoid Nano Every</li></ul> | ~$8 |  <ul><li>14 Digital I/O (6 PWM)</li><li>6 analog input</li></ul> | 32kb Flash |  16MHz |
| Arduino Pro Mini       |  <ul><li>Great library compatability</li><li>very small size</li><li>Careful with power inputs (comes in 5V or 3.3 V)</li><li>Requires HTMI programmer</li></ul> | ~$5 |  <ul><li>14 Digital I/O (6 PWM)</li><li>6 analog input</li></ul> | 32kb Flash | 16MHz |
| Particle Photon    |  <ul><li>Has WiFi!</li><li>great support on server side for GET and POST parsing</li><li>small size</li><li>built on ESP32 platform</li></ul> |$19.65  |    <ul><li>8 Digital I/O (4 PWM)</li><li>8 analog input</li></ul>   |        1MB Flash    | 120Mhz | 
| Teensy 3.2         | <ul><li>Fast Processor</li><li>lots of pins</li><li>Great accuracy for sensitive measurements</li><li>some pins are hard to access</li><li>small size</li><li>check out compatable MP3 breakout</li></ul> |$19.80 |   <ul><li>34 digital I/Ou pins (12 PWM)</li><li>21 analog input (1 analog output, 12 capacitive touch)</li></ul>    | 256K Flash           | 72 MHz |
| ATTINY 85        | <ul><li>super small</li><li>Requires advanced circut knowledge</li></ul> |$2.80 |   <ul><li>6 digital I/O pins (3 PWM, 3 Analog input)</li></ul>    | 8kb Flash           | 8 MHz |
| ESP32              | Content Cell  |                                        |            |


