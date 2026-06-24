#include <Arduino.h>

#include "actuators/servo_scanner.h"
#include "config/roomflow_config.h"

ServoScanner scanner(SERVO_PIN);

void setup() {

    scanner.begin();
}

void loop() {

    scanner.sweep();
}