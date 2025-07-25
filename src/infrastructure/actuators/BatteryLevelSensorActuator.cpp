#include "infrastructure/actuators/BatteryLevelSensorActuator.h"

BatteryLevelSensorActuator::BatteryLevelSensorActuator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void BatteryLevelSensorActuator::setState(bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
}

void BatteryLevelSensorActuator::update() {
    
}
