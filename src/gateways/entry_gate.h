#ifndef ENTRY_GATE_H
#define ENTRY_GATE_H

#include "sensors/entry_gate_sensor.h"
#include "actuators/servo_scanner.h"

class EntryGate
{
public:
    EntryGate();

    void begin();

    void update();

    // Getters
    float getLeftDistance() const;
    float getCenterDistance() const;
    float getRightDistance() const;

private:
    EntryGateSensor _sensor;
    ServoScanner _scanner;

    float _leftDistance;
    float _centerDistance;
    float _rightDistance;
};

#endif