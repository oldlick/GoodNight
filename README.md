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
  ![MicrobitModules.jpg](/Image/MicrobitModules.jpg)  
  ![MicrobitPins.jpg](/Image/MicrobitPins.jpg)  
  ![MicrobitHumansensor.jpg](/Image/MicrobitHumansensor.jpg)

### RaspberryPi
- clone on RaspberryPi.
  - $ git clone https://github.com/oldlick/GoodNight/tree/master/RaspberryPi GoodNight
- If nodejs does not exist, download it.
  - $ sudo apt-get install nodejs
- If pigpio does not exist, download it.
  - $ sudo apt-get install pigpio
- Compile ir.cpp.
  - $ g++ ir.cpp -o ir -lpigpio
- Make a circuit.
  - Connect to RaspberryPi. IR-LED and IR-sensor.
  - Refer to Image folder.  
  ![MicrobitModules.jpg](/Image/RaspberrypiModules.jpg)

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
- Change the infrared signal to be sent.
  - $ ./ir
  - Send a signal to the infrared sensor.
  - Write the displayed value to codeData.txt.
  - Line 1 of codeData.txt: Turn on the light
  - Line 2: Turn off the lights.
  - Line 3: Turn on the air conditioning.
  - Line 4: Turn off the air conditioning.
|  TH  |  TH  |
| ---- | ---- |
|  TD  |  TD  |
|  TD  |  TD  |
