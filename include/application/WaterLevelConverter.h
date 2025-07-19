#ifndef WATER_LEVEL_CONVERTER_H
    #define WATER_LEVEL_CONVERTER_H

    #include "infrastructure/sensors/PCF8574Input.h"

    class WaterLevelConverter {
    private:
        PCF8574Input& waterSensor1;
        PCF8574Input& waterSensor2;
        PCF8574Input& waterSensor3;
        PCF8574Input& waterSensor4;
        PCF8574Input& waterSensor5;
        PCF8574Input& waterSensor6;
        PCF8574Input& waterSensor7;

    public:
        WaterLevelConverter(
            PCF8574Input& waterSensor1, 
            PCF8574Input& waterSensor2, 
            PCF8574Input& waterSensor3, 
            PCF8574Input& waterSensor4, 
            PCF8574Input& waterSensor5, 
            PCF8574Input& waterSensor6, 
            PCF8574Input& waterSensor7
        );
        int getPercent();
        String getPercentRange();
        String getLitersRange();
    };

#endif
