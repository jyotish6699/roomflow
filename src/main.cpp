#include <Arduino.h>

#include "gateways/entry_gate.h"
#include "gateways/exit_gate.h"
#include "events/event.h"
#include "events/event_type.h"
#include "occupancy/occupancy_state_machine.h"
#include "occupancy/occupancy_state.h"
#include "occupancy/occupancy_engine.h"

EntryGate entryGate;
ExitGate exitGate;

OccupancyEngine occupancyEngine;

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

    occupancyEngine.update(entryEvent);
    occupancyEngine.update(exitEvent);

    Serial.println("================================");

    Serial.print("State      : ");
    Serial.println(
        occupancyStateToString(
            occupancyEngine.getState()
        )
    );

    Serial.print("Entry Event: ");
    Serial.println(
        eventToString(entryEvent.type)
    );

    Serial.print("Exit Event : ");
    Serial.println(
        eventToString(exitEvent.type)
    );

    Serial.print("Occupancy  : ");
    Serial.println(
        occupancyEngine.getOccupancyCount()
    );

    Serial.println("================================");

    delay(100);
}