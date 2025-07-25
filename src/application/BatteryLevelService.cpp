#include "application/BatteryLevelService.h"
#include "infrastructure/env.h"

BatteryLevelService::BatteryLevelService(
    BatteryLevelSensorActuator& batteryLevelSensorActuator, 
    BatteryLevelSensor& batteryLevelSensor
) : batteryLevelSensorActuator(batteryLevelSensorActuator),
    batteryLevelSensor(batteryLevelSensor)
{
}

float BatteryLevelService::getPercent() 
{
    float voltage = this->getVoltage();

    return (voltage - BATTERY_MIN_LEVEL) / (BATTERY_MAX_LEVEL - BATTERY_MIN_LEVEL) * 100;
}

float BatteryLevelService::getVoltage() 
{
    this->batteryLevelSensorActuator.setState(HIGH);

    float batteryLevel = this->batteryLevelSensor.readValue();

    this->batteryLevelSensorActuator.setState(LOW);

    return batteryLevel;
}
