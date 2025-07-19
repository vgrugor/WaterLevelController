#include "infrastructure/sensors/PCF8574Input.h"
#include <Arduino.h>

PCF8574Input::PCF8574Input(PCF8574& pcf, int pin, unsigned long updateInterval)
    : pcf(pcf), 
    pin(pin), 
    Sensor(updateInterval) 
{
    this->lastState = this->readValue();
}

float PCF8574Input::readValue() {
    this->lastState = pcf.read(pin);

    return this->lastState ? 1.0 : 0.0;
}

bool PCF8574Input::isHigh() {
    return this->readValue() > 0.0;
}
