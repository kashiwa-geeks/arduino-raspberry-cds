# arduino-raspberry-cds
2016/12/4に開催された「[Arduino もくもく in 柏の葉KOIL](https://kashiwano-ha-geeks.connpass.com/event/46211/)」で @mascii がCdSとLEDを用いてArduinoを試してみたときに作成したものです。Raspberry Piと連携してみたりしました。

## 01-arduino-cds-led
(Arduino) CdSに当たった光量に応じてLEDの光量を変える例です。  

- CdSの接続は、5VとA0に220Ω程度の抵抗を挟み、A0とGND(5Vに近いところにある方)にCdSを挟む感じです
- LEDの接続は、10番ピン(PWMが使える)とGNDに抵抗とLEDを直列に接続します
- `analogRead` で取れる値は0から1023まで、 `analogWrite` の第2引数の値(デューティ比)は 0から255までの整数値です
  - CdSは受光した光量が多いほど抵抗値が小さくなり、`analogRead` で取れる値が小さくなります
  - `analogWrite` の第2引数の値が大きいほど、LEDは明るくなります
- このサンプルでは、CdSが受光した光量が多いほど、LEDが明るくなります
- こちらを参考にしました: [光センサーでArduinoへの入力を試してみる！ | Device Plus - デバプラ](http://deviceplus.jp/hobby/entry_005/)

## 02-arduino-pc-cds
(Arduino + PC) CdSに当たった光量をPC側で取得する例です。  

- CdSの接続は、01-arduino-cds-ledと同じです。
- pyserialを `pip install pyserial` で入れて、 PCとArduinoをUSB接続すると、 `python read.py` で値を取れます。
  - Arduino IDEのシリアルモニタでも同じことができます

## 03-arduino-pc-led
(Arduino + PC) 3色LEDの色をPC側からコマンドを送って変える例です。  

- 3色LEDの接続は、11番ピンにR(赤)、10番ピンにB(青)、9番ピンにG(緑)、GNDとコモンアノードを接続します
  - R,G,Bと各番号ピンの間には、抵抗も入れておいてください
- pyserialを `pip install pyserial` で入れて、 PCとArduinoをUSB接続すると、 `python send.py` でコマンドを送れます。
  - `r1`と打ってEnterキーを押すと、赤色LEDが点灯し、`g0`と打ってEnterキーを押すと、緑色LEDが消灯する感じです。
  - Arduino IDEのシリアルモニタでも同じことができます
    - ただし、`r1.` のように終端文字 `.` も送る必要があります
- こちらを参考にしました: [【Arduino/Python】シリアル通信でPCからLED点灯制御](http://denshi.blog.jp/arduino/serial_led_python)
- こちらを参考にしました: [Arduinoにおけるコマンドラインインタフェースの雛型 - Imaginable Reality](http://d.hatena.ne.jp/kougaku-navi/20141105/p1)
  - こちらの方法の方が確実に動作しました

## 04-arduino-raspberry-cds-led
(Arduino + Raspberry) Arduino側はCdSに当たった光量に応じて3色LEDの光量を変えつつ、Raspberry Pi側はサーバーとして機能しブラウザからの操作で3色LEDの色を変えることができる例です。  

- CdSの接続は、01-arduino-cds-ledと同じです。
- 3色LEDの接続は、03-arduino-pc-ledと同じです。
  - 11,10,9番ピンのように、PWMが使えるところを使ってください
- Raspbery PiとArduinoをUSBで接続し、Raspbery PiにNode.jsとnpmをインストール、 `npm install` して `node app` で、HTTPサーバーがポート番号 `50359` で立ち上がります。
  - ブザウザで3色LEDの色のオンオフができます

