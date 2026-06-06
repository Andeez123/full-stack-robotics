#include <Arduino.h>
#include <driver/ledc.h>

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14;

int motor1Pin3 = 25; 
int motor1Pin4 = 33; 
int enable2Pin = 32;

const int freq = 10000;
const int pwmChannelA = 0;
const int pwmChannelB = 1;
const int resolution = 8;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);

  ledcSetup(pwmChannelA, freq, resolution);
  ledcSetup(pwmChannelB, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannelA);
  ledcAttachPin(enable2Pin, pwmChannelB);

  ledcWrite(pwmChannelA, 100);
  ledcWrite(pwmChannelB, 55);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Move DC motor forward
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
  delay(2000);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  delay(1000);

  // //move forward with increasing speed
  // digitalWrite(motor1Pin1, LOW);
  // digitalWrite(motor1Pin2, HIGH);
  // for (dutyCycle = 170; dutyCycle < 255; dutyCycle++) {
  //   ledcWrite(pwmChannel, dutyCycle);
  //   delay(20);
  // }

  // dutyCycle = 170;
  // ledcWrite(pwmChannel, dutyCycle);
}