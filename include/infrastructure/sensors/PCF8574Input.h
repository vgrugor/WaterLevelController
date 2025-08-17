#ifndef PCF8574_INPUT_H
    #define PCF8574_INPUT_H

    #include "domain/Sensor.h"
    #include <PCF8574.h>

    class PCF8574Input : public Sensor {
    private:
        PCF8574& pcf;
        int pin;
        bool lastState;

    public:
        PCF8574Input(PCF8574& pcf, int pin, unsigned long updateInterval = 0);
        float readValue() override;
        bool isHigh();
        void setLow();
        void setHigh();
    };

#endif
