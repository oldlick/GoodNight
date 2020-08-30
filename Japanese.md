# GoodNight
## オープンソース・ライセンス
- オープンソース・ライセンスはREADME.mdの通りである。

## コンセプト
- 睡眠の管理をして快眠を促す。
- 眠ったことを検知し、起きたい時間に電気をつける。
- Micro::bitを枕元に、RaspberryPiを机に置いて使用する。

## 準備
### Micro::bit
- CHIRIMENのイメージをMicro::bitに書き込む。
  - CHIRIMEN with micro:bit : https://makecode.microbit.org/_Jh51P7beW6Kb
- 回路を作る。
  - 写真を参考にして、Micro::bitにサーモグラフィーと温度センサー、人感センサーをつなぐ。  
  ![MicrobitModules.jpg](/Image/MicrobitModules.jpg)  
  ![MicrobitPins.jpg](/Image/MicrobitPins.jpg)  
  ![MicrobitHumansensor.jpg](/Image/MicrobitHumansensor.jpg)

### RaspberryPi
- コードをRaspberryPiにコピーする。
  - $ git clone https://github.com/oldlick/GoodNight/tree/master/Code GoodNight
- nodejsをインストールする。
  - $ sudo apt-get install nodejs
- pigpioをインストールする。
  - $ sudo apt-get install pigpio
- ir.cppをコンパイルする。
  - $ g++ ir.cpp -o ir -lpigpio
- 回路を作る。
  - 写真を参考にして、ラズパイに赤外線LEDと赤外線センサーをつなぐ。  
  ![MicrobitModules.jpg](/Image/RaspberrypiModules.jpg)

### option
- Change the infrared signal to be sent.
  - $ ./ir
  - Send a signal to the infrared sensor.
  - Write the displayed value to codeData.txt.
  - codeData.txt's line:
  - Line 1: Turn on the light.
  - Line 2: Turn off the lights.
  - Line 3: Turn on the air conditioning.
  - Line 4: Turn off the air conditioning.  
- Use a 3D printer to print a compact base of Micro::bit.
  - The 3D data is in MicrobitBase.stl
  ![MicrobitBase.jpg](/Image/MicrobitBase.jpg)  
  ![MicrobitAssemble.jpg](/Image/MicrobitAssemble.jpg)



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
