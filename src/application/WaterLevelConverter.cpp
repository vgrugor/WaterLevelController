#include "application/WaterLevelConverter.h"

WaterLevelConverter::WaterLevelConverter(
    PCF8574Input& waterSensor1, 
    PCF8574Input& waterSensor2, 
    PCF8574Input& waterSensor3, 
    PCF8574Input& waterSensor4, 
    PCF8574Input& waterSensor5, 
    PCF8574Input& waterSensor6, 
    PCF8574Input& waterSensor7,
    WaterCommonPinActuator& waterCommonPinActuator
) : waterSensor1(waterSensor1),
    waterSensor2(waterSensor2),
    waterSensor3(waterSensor3),
    waterSensor4(waterSensor4),
    waterSensor5(waterSensor5),
    waterSensor6(waterSensor6),
    waterSensor7(waterSensor7),
    waterCommonPinActuator(waterCommonPinActuator)
{
}

int WaterLevelConverter::getLiter() 
{
    this->waterCommonPinActuator.setState(HIGH);

    this->activateSensor(7);
    if (!this->waterSensor7.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_7_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_7_LEVEL_LITER;
    }

    this->activateSensor(6);
    if (!this->waterSensor6.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_6_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_6_LEVEL_LITER;
    }

    this->activateSensor(5);
    if (!this->waterSensor5.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_5_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_5_LEVEL_LITER;
    }

    this->activateSensor(4);
    if (!this->waterSensor4.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_4_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_4_LEVEL_LITER;
    }

    this->activateSensor(3);
    if (!this->waterSensor3.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_3_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_3_LEVEL_LITER;
    }

    this->activateSensor(2);
    if (!this->waterSensor2.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_2_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_2_LEVEL_LITER;
    }

    this->activateSensor(1);
    if (!this->waterSensor1.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_WATER_LEVEL, 
            String(WATER_SENSOR_1_LEVEL_LITER)
        );

        this->waterCommonPinActuator.setState(LOW);
        this->activateSensor(0);

        return WATER_SENSOR_1_LEVEL_LITER;
    }

    this->waterCommonPinActuator.setState(LOW);
    this->activateSensor(0);
    EventNotifier::getInstance().notifyObservers(
        EventType::READ_WATER_LEVEL, 
        String(WATER_MIN_LEVEL_LITER)
    );

    return WATER_MIN_LEVEL_LITER;
}

void WaterLevelConverter::activateSensor(int sensorNumber) {
    this->waterSensor1.setLow();
    this->waterSensor2.setLow();
    this->waterSensor3.setLow();
    this->waterSensor4.setLow();
    this->waterSensor5.setLow();
    this->waterSensor6.setLow();
    this->waterSensor7.setLow();

    switch (sensorNumber) {
        case 1: this->waterSensor1.setHigh(); break;
        case 2: this->waterSensor2.setHigh(); break;
        case 3: this->waterSensor3.setHigh(); break;
        case 4: this->waterSensor4.setHigh(); break;
        case 5: this->waterSensor5.setHigh(); break;
        case 6: this->waterSensor6.setHigh(); break;
        case 7: this->waterSensor7.setHigh(); break;
        default: break;
    }
}
