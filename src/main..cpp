#include <Arduino.h>

const int motor1Pin1 = 27;  // IN1
const int motor1Pin2 = 26;  // IN2
const int enable1Pin = 14;  // ENA (PWM)

const int pwmChannel = 0;
const int pwmFreq = 1000;
const int pwmResolution = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test starting...");

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  // Configure PWM
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(enable1Pin, pwmChannel);

  // Full speed (0-255 for 8-bit resolution)
  ledcWrite(pwmChannel, 255);

  // Set motor direction
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);

  Serial.println("Motor should be spinning.");
}

void loop() {
  // Nothing to do
}