#include "infrastructure/actuators/WaterCommonPinActuator.h"

WaterCommonPinActuator::WaterCommonPinActuator(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void WaterCommonPinActuator::setState(bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
}

void WaterCommonPinActuator::update() {
    
}
