#include "gateways/entry_gate.h"
#include "config/roomflow_config.h"

#include <Arduino.h>

EntryGate::EntryGate()
    : _sensor(ENTRY_TRIG_PIN, ENTRY_ECHO_PIN),
      _scanner(SERVO_PIN),
      _leftDistance(-1),
      _centerDistance(-1),
      _rightDistance(-1)
{
}

void EntryGate::begin()
{
    _sensor.begin();
    _scanner.begin();
}

void EntryGate::update()
{
    _scanner.moveLeft();
    delay(SERVO_SETTLE_TIME_MS);
    _leftDistance = _sensor.getDistance();

    _scanner.center();
    delay(SERVO_SETTLE_TIME_MS);
    _centerDistance = _sensor.getDistance();

    _scanner.moveRight();
    delay(SERVO_SETTLE_TIME_MS);
    _rightDistance = _sensor.getDistance();
}

float EntryGate::getLeftDistance() const
{
    return _leftDistance;
}

float EntryGate::getCenterDistance() const
{
    return _centerDistance;
}

float EntryGate::getRightDistance() const
{
    return _rightDistance;
}