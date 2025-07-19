#include "application/WaterLevelConverter.h"
#include "infrastructure/env.h"

WaterLevelConverter::WaterLevelConverter(
    PCF8574Input& waterSensor1, 
    PCF8574Input& waterSensor2, 
    PCF8574Input& waterSensor3, 
    PCF8574Input& waterSensor4, 
    PCF8574Input& waterSensor5, 
    PCF8574Input& waterSensor6, 
    PCF8574Input& waterSensor7
) : waterSensor1(waterSensor1),
    waterSensor2(waterSensor2),
    waterSensor3(waterSensor3),
    waterSensor4(waterSensor4),
    waterSensor5(waterSensor5),
    waterSensor6(waterSensor6),
    waterSensor7(waterSensor7)
{
}

int WaterLevelConverter::getPercent() 
{
    if (this->waterSensor1.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_1_LEVEL_PERCENT)
        );

        return WATER_SENSOR_1_LEVEL_PERCENT;
    }

    if (this->waterSensor2.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_2_LEVEL_PERCENT)
        );

        return WATER_SENSOR_2_LEVEL_PERCENT;
    }

    if (this->waterSensor3.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_3_LEVEL_PERCENT)
        );

        return WATER_SENSOR_3_LEVEL_PERCENT;
    }

    if (this->waterSensor4.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_4_LEVEL_PERCENT)
        );

        return WATER_SENSOR_4_LEVEL_PERCENT;
    }

    if (this->waterSensor5.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_5_LEVEL_PERCENT)
        );

        return WATER_SENSOR_5_LEVEL_PERCENT;
    }

    if (this->waterSensor6.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_6_LEVEL_PERCENT)
        );

        return WATER_SENSOR_6_LEVEL_PERCENT;
    }

    if (this->waterSensor7.isHigh()) {
        EventNotifier::getInstance().notifyObservers(
            EventType::READ_TEMPERATURE, 
            String(WATER_SENSOR_3_LEVEL_PERCENT)
        );

        return WATER_SENSOR_7_LEVEL_PERCENT;
    }

    EventNotifier::getInstance().notifyObservers(
        EventType::READ_TEMPERATURE, 
        String(WATER_MIN_LEVEL_PERCENT)
    );

    return WATER_MIN_LEVEL_PERCENT;
}

String WaterLevelConverter::getPercentRange() 
{
    unsigned int percent = this->getPercent();

    if (percent == WATER_SENSOR_1_LEVEL_PERCENT) {
        return WATER_SENSOR_1_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_2_LEVEL_PERCENT) {
        return WATER_SENSOR_2_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_3_LEVEL_PERCENT) {
        return WATER_SENSOR_3_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_4_LEVEL_PERCENT) {
        return WATER_SENSOR_4_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_5_LEVEL_PERCENT) {
        return WATER_SENSOR_5_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_6_LEVEL_PERCENT) {
        return WATER_SENSOR_6_LEVEL_PERCENT_RANGE;
    }

    if (percent == WATER_SENSOR_7_LEVEL_PERCENT) {
        return WATER_SENSOR_7_LEVEL_PERCENT_RANGE;
    }

    return WATER_MIN_LEVEL_PERCENT_RANGE;
}

String WaterLevelConverter::getLitersRange()
{
    unsigned int percent = this->getPercent();

    if (percent == WATER_SENSOR_1_LEVEL_PERCENT) {
        return WATER_SENSOR_1_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_2_LEVEL_PERCENT) {
        return WATER_SENSOR_2_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_3_LEVEL_PERCENT) {
        return WATER_SENSOR_3_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_4_LEVEL_PERCENT) {
        return WATER_SENSOR_4_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_5_LEVEL_PERCENT) {
        return WATER_SENSOR_5_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_6_LEVEL_PERCENT) {
        return WATER_SENSOR_6_LEVEL_LITER_RANGE;
    }

    if (percent == WATER_SENSOR_7_LEVEL_PERCENT) {
        return WATER_SENSOR_7_LEVEL_LITER_RANGE;
    }

    return WATER_MIN_LEVEL_LITER_RANGE;
}
