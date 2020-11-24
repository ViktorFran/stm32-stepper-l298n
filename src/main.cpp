#include <Arduino.h>
#include <Stepper.h>
#define potPin PB1
#define led PB0
#define button1 PB14
#define button2 PA8
#define stopBut PA10

const int totalSteps = 200;
signed int direction = 0;

Stepper motor = Stepper(totalSteps, PB6, PB7, PB8, PB9);
void stop() {
    direction = 0;
    digitalWrite(LED_BUILTIN, 1);
    int pot = analogRead(potPin);
    int speed = map(pot, 0, 4095, 0, 600);
    int brightness = map(pot, 0, 4095, 0, 255);
    analogWrite(led, brightness);
    motor.setSpeed(speed);
}
void turn1() {
    direction = 1;
    digitalWrite(LED_BUILTIN, 0);
    int pot = analogRead(potPin);
    int speed = map(pot, 0, 4095, 0, 600);
    int brightness = map(pot, 0, 4095, 0, 255);
    analogWrite(led, brightness);
    motor.setSpeed(speed);
}
void turn2() {
    direction = -1;
    digitalWrite(LED_BUILTIN, 0);
    int pot = analogRead(potPin);
    int speed = map(pot, 0, 4095, 0, 600);
    int brightness = map(pot, 0, 4095, 0, 255);
    analogWrite(led, brightness);
    motor.setSpeed(speed);
}
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(stopBut, INPUT_PULLUP); 
    attachInterrupt(button1, turn1, CHANGE);    
    attachInterrupt(button2, turn2, CHANGE);
    attachInterrupt(stopBut, stop, CHANGE);
    motor.setSpeed(10);
 }

void loop() {
    motor.step(direction * 10);
}