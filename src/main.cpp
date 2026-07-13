#include <Arduino.h>

#include "gateways/entry_gate.h"
#include "sensors/exit_gate_sensor.h"
#include "config/roomflow_config.h"

EntryGate entryGate;

ExitGateSensor exitSensor(
    EXIT_TRIG_PIN,
    EXIT_ECHO_PIN
);

void setup()
{
    Serial.begin(9600);

    entryGate.begin();
    exitSensor.begin();
}

void loop()
{
    entryGate.update();

    float exitDistance = exitSensor.getDistance();

    Serial.println("==========");

    Serial.print("LEFT: ");
    Serial.println(entryGate.getLeftDistance());

    Serial.print("CENTER: ");
    Serial.println(entryGate.getCenterDistance());

    Serial.print("RIGHT: ");
    Serial.println(entryGate.getRightDistance());

    Serial.print("EXIT: ");
    Serial.println(exitDistance);

    delay(100);
}