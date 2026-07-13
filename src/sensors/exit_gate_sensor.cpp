#include "exit_gate_sensor.h"
#include "config/roomflow_config.h"

#include <Arduino.h>

// Constructor definition
ExitGateSensor::ExitGateSensor(int trigPin, int echoPin)
{
    _trigPin = trigPin;
    _echoPin = echoPin;
}

// begin() definition
void ExitGateSensor::begin()
{
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);

    digitalWrite(_trigPin, LOW);
}

// getDistance() definition
float ExitGateSensor::getDistance()
{
    // Clear trigger pin
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Send 10us pulse
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Read echo duration
    long duration = pulseIn(_echoPin, HIGH);

    if (duration == 0)
    {
        return -1;
    }

    // Convert to centimeters
    float distance = duration * 0.0343 / 2.0;

    return distance;
}

// isTriggered() definition
bool ExitGateSensor::isTriggered()
{
    float distance = getDistance();

    if (distance < 0)
    {
        return false;
    }

    return distance < EXIT_THRESHOLD_CM;
}