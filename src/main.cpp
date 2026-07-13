#include <Arduino.h>

#include "sensors/entry_gate_sensor.h"
#include "actuators/servo_scanner.h"
#include "config/roomflow_config.h"
#include "sensors/exit_gate_sensor.h"

EntryGateSensor entrySensor(
    ENTRY_TRIG_PIN,
    ENTRY_ECHO_PIN
);

ExitGateSensor exitSensor(
    EXIT_TRIG_PIN,
    EXIT_ECHO_PIN
);

ServoScanner scanner(SERVO_PIN);

void setup()
{
    Serial.begin(9600);

    entrySensor.begin();
    scanner.begin();
    exitSensor.begin();
}

void loop()
{
    scanner.moveLeft();
    delay(SERVO_SETTLE_TIME_MS);

    float leftDistance =
        entrySensor.getDistance();

    scanner.center();
    delay(SERVO_SETTLE_TIME_MS);

    float centerDistance =
        entrySensor.getDistance();

    scanner.moveRight();
    delay(SERVO_SETTLE_TIME_MS);

    float rightDistance =
        entrySensor.getDistance();

    Serial.println("==========");

    Serial.print("LEFT: ");
    Serial.println(leftDistance);

    Serial.print("CENTER: ");
    Serial.println(centerDistance);

    Serial.print("RIGHT: ");
    Serial.println(rightDistance);

    float exitDistance = exitSensor.getDistance();

    Serial.print("EXIT: ");
    Serial.println(exitDistance);

    delay(100);
}