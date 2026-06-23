#include "entry_gate_sensor.h"
#include "config/roomflow_config.h"
#include <Arduino.h>

// Constructor defination
EntryGateSensor::EntryGateSensor(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
}

// begin() defination
void EntryGateSensor::begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);

    digitalWrite(_trigPin, LOW);
}

// getDistance() defination
float EntryGateSensor::getDistance() {

    // Clear trigger pin
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Send 10us pulse
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Read echo duration 
    long duration = pulseIn(_echoPin, HIGH);

    if(duration == 0) {
        return -1;
    }

    //Convert to cm
    float distance = duration * 0.0343 / 2.0;
    return distance;

}

bool EntryGateSensor::isTriggered()
{
    float distance = getDistance();

    if(distance < 0)
    {
        return false;
    }

    return distance < ENTRY_THRESHOLD_CM;
}