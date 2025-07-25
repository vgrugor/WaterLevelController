#include "infrastructure/sensors/BatteryLevelSensor.h"

BatteryLevelSensor::BatteryLevelSensor(int pin, unsigned long updateInterval) : Sensor(updateInterval), pin(pin)
{
}

float BatteryLevelSensor::readValue() {
    int batteryLevel = this->readAvg(COUNT_BATTERY_LEVEL_READ);

    float voltage = batteryLevel / 1023.0 * V_REF * BATTERY_MAX_LEVEL;

    String voltageString = String(voltage, 2);

    EventNotifier::getInstance().notifyObservers(EventType::READ_BATTERY_LEVEL, voltageString);

    return voltage;
}

int BatteryLevelSensor::readAvg(unsigned int countRead) {
    int sum = 0;

    for (unsigned int i = 0; i < countRead; i++) {
        sum += analogRead(this->pin);
        delay(10);
    }

    return sum / countRead;
}
