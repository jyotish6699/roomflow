#include <Arduino.h>

#include "gateways/entry_gate.h"
#include "gateways/exit_gate.h"

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

    Serial.println("==========");

    Serial.print("LEFT: ");
    Serial.println(entryGate.getLeftDistance());

    Serial.print("CENTER: ");
    Serial.println(entryGate.getCenterDistance());

    Serial.print("RIGHT: ");
    Serial.println(entryGate.getRightDistance());

    Serial.print("EXIT: ");
    Serial.println(exitGate.getDistance());

    delay(100);
}