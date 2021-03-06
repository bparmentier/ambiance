/*
 * Author Bruno Parmentier
 * http://www.brunoparmentier.be
 *
 * This sketch automatically turns on the music on a RPi, an IR led strip and a
 * mood lamp when the LDR output is below a certain amount of light.
 *
 * Mood lamp inspired by http://www.instructables.com/id/Mood-Lamp-with-Arduino/
 *
 * IR LED on PWM pin 3;
 * LDR (photoresistor) on analog pin A0;
 *
 */

#include <IRremote.h>

/* LDR */
int LDRPin = A0; 
int LDRReading; // light value read by the sensor
int state; // system state: ON = 1, OFF = 0
int light_value = 100; // light limit

/* Color leds */
float RGB[3];
int redLed = 6;
int greenLed = 9;
int blueLed = 10;

/* IR led */
IRsend irsend;

void setup(){
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  digitalWrite(13, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);

  LDRReading = analogRead(LDRPin);
  (LDRReading < light_value) ? state = 0 : state = 1;
}

void loop(){
  for (float x = 0; x < PI; x += 0.00003) {
    
    /* Define red, green and blue led brightness values */
    RGB[0] = 255 * abs(sin(x * (180 / PI)));
    RGB[1] = 255 * abs(sin((x + PI / 3) * (180 / PI)));
    RGB[2] = 255 * abs(sin((x + (2 * PI) / 3) * (180 / PI)));

    /* Read LDR value */
    LDRReading = analogRead(LDRPin);

    if (LDRReading < light_value) {
      analogWrite(redLed, RGB[0]);
      analogWrite(greenLed, RGB[1]);
      analogWrite(blueLed, RGB[2]);
      
      if (state == 0) {
        for (int i = 0; i < 5; i++) {
          irsend.sendNEC(0xf7c03f, 32); // turn led strip ON
        }
        state = 1;
        Serial.println("ON");
      }
    } else if (LDRReading >= light_value) {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      
      if (state == 1) {
        for (int i = 0; i < 5; i++) {
          irsend.sendNEC(0xf740bf, 32); // turn led strip off
        }
        state = 0;
        Serial.println("OFF");
      }
    }

    for (int i = 0; i < 3; i++) {
      if (RGB[i] < 1) {
        delay(100);
      }
      if (RGB[i] < 5) {
        delay(50);
      }
      if (RGB[i] < 10) {
        delay(10);
      }
      if (RGB[i] < 100) {
        delay(5);
      }
    }
    delay(1);
  }
}

