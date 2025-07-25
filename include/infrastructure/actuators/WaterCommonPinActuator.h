#ifndef WATER_COMMON_PIN_ACTUATOR_H
    #define WATER_COMMON_PIN_ACTUATOR_H

    #include "domain/Actuator.h"
    #include <Arduino.h>

    class WaterCommonPinActuator : public Actuator {
        private:
            int pin;

        public:
            WaterCommonPinActuator(int pin);
            void setState(bool state) override;
            void update() override;
    };

#endif
