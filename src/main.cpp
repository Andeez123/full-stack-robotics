#include <Arduino.h>
#include <driver/ledc.h>

int motor1Pin1 = 27; // control direction
int motor1Pin2 = 26; 
int enable1Pin = 14; //control motor speeds

int motor1Pin3 = 25; 
int motor1Pin4 = 33; 
int enable2Pin = 32;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 170;

const int moveForwardPin = 18;
const int moveBackwardsPin = 19;
int forwardState = 0;
int backwardState = 0;

void stopMotors(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
}

void moveForward(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
}

void moveBackward(){
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
}

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel);
  ledcWrite(pwmChannel, dutyCycle);

  pinMode(moveBackwardsPin, INPUT);
  pinMode(moveForwardPin, INPUT);

  stopMotors();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  forwardState = digitalRead(moveForwardPin);
  backwardState = digitalRead(moveBackwardsPin);
  if (forwardState == LOW && backwardState == HIGH){
    moveForward();
  } else if (backwardState == LOW && forwardState == HIGH){
    moveBackward();
  }
  else {
    stopMotors();
  }
  

  

  // delay(1000);

  // //move forward with increasing speed
  // digitalWrite(motor1Pin1, HIGH);
  // digitalWrite(motor1Pin2, LOW);
  // for (dutyCycle = 170; dutyCycle < 255; dutyCycle++) {
  //   ledcWrite(pwmChannel, dutyCycle);
  //   delay(20);
  // }

  // dutyCycle = 170;
  // ledcWrite(pwmChannel, dutyCycle);
}