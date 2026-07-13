#ifndef EXIT_GATE_H
#define EXIT_GATE_H

#include "sensors/exit_gate_sensor.h"

class ExitGate
{
public:
    ExitGate();

    void begin();

    void update();

    float getDistance() const;

private:
    ExitGateSensor _sensor;

    float _distance;
};

#endif