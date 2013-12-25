ambiance
========

Usage
-----
When the room is dark, the IR led turns on the led strip, the "mood lamp" is
activated, and the music starts.

For the "mood lamp", see this Instructable:
[Mood Lamp with Arduino](http://www.instructables.com/id/Mood-Lamp-with-Arduino/)

Schematics
----------
An Arduino Uno is connected to the USB port of a Raspberry Pi.

* IR led connected to pin 3 (PWM);
* light-dependent resistor (LDR) connected to pin A0 (analog);
* 3 leds (red, green, blue) connected to pins 6, 9, 10 (PWM).

![ambiance-schematics](ambiance-schematics.png)

Libraries
---------
* Arduino: [Arduino-IRremote](https://github.com/shirriff/Arduino-IRremote)
* Raspberry Pi: [pySerial](http://pyserial.sourceforge.net/)

Led strip NEC codes
-------------------

<table>
  <tr>
    <th>Color</th><th>Code</th>
  </tr>

  <tr>
    <td>Brightness+</td><td>F700FF</td>
  </tr>
  <tr>
    <td>Static red</td><td>F720DF</td>
  </tr>
  <tr>
    <td>Static rose red</td><td>F710EF</td>
  </tr>
  <tr>
    <td>Static orange</td><td>F730CF</td>
  </tr>
  <tr>
    <td>Static light yellow</td><td>F708F7</td>
  </tr>
  <tr>
    <td>Static yellow</td><td>F728D7</td>
  </tr>

  <tr>
    <td>Brightness-</td><td>F7807F</td>
  </tr>
  <tr>
    <td>Static green</td><td>F7A05F</td>
  </tr>
  <tr>
    <td>Static light green</td><td>F7906F</td>
  </tr>
  <tr>
    <td>Static green blue</td><td>F7B04F</td>
  </tr>
  <tr>
    <td>Static sky blue</td><td>F78877</td>
  </tr>
  <tr>
    <td>Static cyan</td><td>F7A857</td>
  </tr>

  <tr>
    <td>OFF</td><td>F740BF</td>
  </tr>
  <tr>
    <td>Static blue</td><td>F7609F</td>
  </tr>
  <tr>
    <td>Static sapphire blue</td><td>F750AF</td>
  </tr>
  <tr>
    <td>Static violet and grey</td><td>F7708F</td>
  </tr>
  <tr>
    <td>Static brown and purple</td><td>F748B7</td>
  </tr>
  <tr>
    <td>Static purple</td><td>F76897</td>
  </tr>

  <tr>
    <td>ON</td><td>F7C03F</td>
  </tr>
  <tr>
    <td>Static white</td><td>F7E01F</td>
  </tr>
  <tr>
    <td>3 colors jump</td><td>F7D02F</td>
  </tr>
  <tr>
    <td>3 colors gradual</td><td>F7F00F</td>
  </tr>
  <tr>
    <td>7 colors gradual</td><td>F7C837</td>
  </tr>
  <tr>
    <td>7 colors jump</td><td>F7E817</td>
  </tr>
