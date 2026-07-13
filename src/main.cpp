#include <Arduino.h>

#include "gateways/entry_gate.h"
#include "gateways/exit_gate.h"
#include "events/event.h"
#include "events/event_type.h"

EntryGate entryGate;
ExitGate exitGate;

void setup()
{
    Serial.begin(9600);

    entryGate.begin();
    exitGate.begin();
}

void loop()
{
    entryGate.update();
    exitGate.update();

    Event entryEvent = entryGate.getEvent();
    Event exitEvent = exitGate.getEvent();

    if (entryEvent.type != EventType::NONE)
    {
        Serial.println(eventToString(entryEvent.type));
    }

    if (exitEvent.type != EventType::NONE)
    {
        Serial.println(eventToString(exitEvent.type));
    }

    delay(100);
}