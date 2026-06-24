#include "actuators/servo_scanner.h"
#include "config/roomflow_config.h"

#include <Arduino.h>
#include <Servo.h>

Servo scannerServo;

ServoScanner::ServoScanner(int servoPin) {

    _servoPin = servoPin;
}

void ServoScanner::begin() {

    scannerServo.attach(_servoPin);

    center();
}

void ServoScanner::center() {

    scannerServo.write(SERVO_CENTER_ANGLE);
}

void ServoScanner::moveLeft() {

    scannerServo.write(SERVO_LEFT_ANGLE);
}

void ServoScanner::moveRight() {

    scannerServo.write(SERVO_RIGHT_ANGLE);
}

void ServoScanner::sweep() {
    
    moveLeft();
    delay(500);

    center();
    delay(500);

    moveRight();
    delay(500);

    center();
}