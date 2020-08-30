# GoodNight
## LICENSE  
This software is released under the MIT License, see LICENSE.txt.

## LANGUAGE
- Japanese.pdf is the explanation in Japanese.

## CONCEPT
- This device manages your sleep.
- Detect sleep and turn on the lights at the time you want to wake up.
- Put Micro::bit on your sleeping area and RaspberryPi on your desk.

## SET UP
### Micro::bit
- Writing CHIRIMEN image to Micro::bit.
  - CHIRIMEN with micro:bit : https://makecode.microbit.org/_Jh51P7beW6Kb
- Make a circuit.
  - Connect to Micro::bit. Thermography, temperature sensor and human sensor.
  - Refer to Image folder.
  - ![image](/Image/598368.jpg)
  - ![image](/Image/598372.jpg)
  - ![image](/Image/598376.jpg)

### RaspberryPi
- clone on RaspberryPi.
  - $ git clone https://github.com/oldlick/GoodNight/tree/master/RaspberryPi GoodNight
- If nodejs does not exist, download it.
  - $ sudo apt-get install nodejs

## HOW TO USE
### Micro::bit
- Put Micro::bit on your sleeping area.
- Turn on the power.
  - Connect the MicroUSB connector to the power supply.
  - Don't use the connector on the Micro::bit. (To supply 5v to the human sensor.)

### RaspberryPi
- Launch the program that controls the RaspberryPi.
  - $ python3 /GoodNight/main.py
- Use the RaspberryPi browser to run the Micro::bit.
  - Open file:///home/pi/Microbit/index.html in the RaspberryPi browser.
  - Press the Connect button.

### option
- @file:///home/pi/Microbit/index.html
  - If you enter a machinist API key, you can record the temperature data in the machinist.
  - [not yet] In the future, I want to make that can keep track of how much sleep.
