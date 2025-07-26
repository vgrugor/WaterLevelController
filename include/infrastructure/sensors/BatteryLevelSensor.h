#ifndef BATTERY_LEVEL_SENSOR_H
    #define BATTERY_LEVEL_SENSOR_H

    #include <Arduino.h>
    #include "domain/Sensor.h"
    #include "presentation/EventType.h"
    #include "infrastructure/env.h"

    class BatteryLevelSensor : public Sensor {
        private:
            int pin;
            int readAvg(unsigned int countRead);

        public:
            BatteryLevelSensor(int pin, unsigned long interval = 0);
            float readValue() override;
    };

#endif // DS18B20SENSOR_H
