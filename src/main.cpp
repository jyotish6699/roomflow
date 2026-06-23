#include <Arduino.h>
#include "sensors/entry_gate_sensor.h"
#include "config/roomflow_config.h"

EntryGateSensor entrySensor(ENTRY_TRIG_PIN, ENTRY_ECHO_PIN);

bool previousState = false;

void setup()
{
    Serial.begin(9600);

    entrySensor.begin();
}

void loop()
{
    float distance = entrySensor.getDistance();

    bool triggered = false;

    if(distance >= 0)
    {
        triggered = distance < ENTRY_THRESHOLD_CM;
    }

    Serial.print("Distance: ");
    Serial.println(distance);

    Serial.print("Triggered: ");
    Serial.println(triggered);

    delay(500);
}