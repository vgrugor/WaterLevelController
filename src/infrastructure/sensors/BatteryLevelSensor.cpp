#include "infrastructure/sensors/BatteryLevelSensor.h"

BatteryLevelSensor::BatteryLevelSensor(int pin, unsigned long updateInterval) : Sensor(updateInterval), pin(pin)
{
}

float BatteryLevelSensor::readValue() {
    int batteryLevel = analogRead(this->pin);

    float voltage = batteryLevel / 1024.0 * V_REF * BATTERY_MAX_LEVEL;

    String voltageString = String(voltage, 2);
    EventNotifier::getInstance().notifyObservers(EventType::READ_TEMPERATURE, voltageString);

    return voltage;
}
