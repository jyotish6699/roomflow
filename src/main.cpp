#include <Arduino.h>

#include "gateways/entry_gate.h"
#include "gateways/exit_gate.h"
#include "events/event.h"
#include "events/event_type.h"
#include "occupancy/occupancy_state_machine.h"
#include "occupancy/occupancy_state.h"

EntryGate entryGate;
ExitGate exitGate;

OccupancyStateMachine stateMachine;

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

    stateMachine.update(entryEvent);
    stateMachine.update(exitEvent);

    Serial.print("State : ");
    Serial.println(
        occupancyStateToString(
            stateMachine.getState()
        )
    );

    delay(100);
}