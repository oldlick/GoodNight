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

### オプション
- 送信する赤外線を変更する。
  - $ ./ir
  - 上記のプログラムを実行中に、センサーに向けて赤外線信号を送る。
  - 表示された数列をcodeData.txtに書き込む。
  - codeData.txtの解釈:
  - 1行目: 照明をつける信号。
  - 2行目: 照明を消す信号。
  - 3行目: エアコンをつける信号。
  - 4行目: エアコンを消す信号。
- 3Dプリンターを用いてMicro::bitをコンパクトにまとめる土台を作る.
  - 3DデータはMicrobitBase.stlとしてImageの中にある。
  ![MicrobitBase.jpg](/Image/MicrobitBase.jpg)  
  ![MicrobitAssemble.jpg](/Image/MicrobitAssemble.jpg)



## 使い方
### Micro::bit
- 枕元に置く。
- 電源をつける。
  - MicroUSBを接続することで給電する。
  - この時Micro::bitに付属しているMicroUSBコネクタにはつながない。(人感センサーに5vを給電するため。)

### RaspberryPi
- RaspberryPiをコントロールするプログラムを起動する。
  - $ python3 /GoodNight/main.py
- ブラウザを用いてMicro::bitと通信する。
  - ブラウザのURLを入力する欄に file:///home/pi/Microbit/index.html と入力する
  - Connectボタンを押す

### オプション
- 気温を記録する。
  - machinist API keyを入力すると、machinistに気温を記録することが出来る。
  - 将来的には、寝ている時間を記録できるようにしたい。
