#include "gateways/exit_gate.h"
#include "config/roomflow_config.h"

ExitGate::ExitGate()
    : _sensor(EXIT_TRIG_PIN, EXIT_ECHO_PIN),
      _distance(-1)
{
}

void ExitGate::begin()
{
    _sensor.begin();
}

void ExitGate::update()
{
    _distance = _sensor.getDistance();
}

float ExitGate::getDistance() const
{
    return _distance;
}

Event ExitGate::getEvent() const
{
    Event event;

    event.type = EventType::NONE;

    if (_distance >= 0 &&
        _distance < EXIT_THRESHOLD_CM)
    {
        event.type = EventType::EXIT_DETECTED;
    }

    return event;
}