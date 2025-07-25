#ifndef BATTERY_LEVEL_SENSOR_ACTUATOR_H
    #define BATTERY_LEVEL_SENSOR_ACTUATOR_H

    #include "domain/Actuator.h"
    #include <Arduino.h>

    class BatteryLevelSensorActuator : public Actuator {
        private:
            int pin;

        public:
            BatteryLevelSensorActuator(int pin);
            void setState(bool state) override;
            void update() override;
    };

#endif
