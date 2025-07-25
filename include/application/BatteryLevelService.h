#ifndef BATTERY_LEVEL_SERVICE_H
    #define BATTERY_LEVEL_SERVICE_H

    #include "infrastructure/actuators/BatteryLevelSensorActuator.h"
    #include "infrastructure/sensors/BatteryLevelSensor.h"
    #include "presentation/EventNotifier.h"

    class BatteryLevelService {
        private:
            BatteryLevelSensorActuator& batteryLevelSensorActuator;
            BatteryLevelSensor& batteryLevelSensor;

        public:
            BatteryLevelService(
                BatteryLevelSensorActuator& batteryLevelSensorActuator, 
                BatteryLevelSensor& batteryLevelSensor
            );
            float getPercent();
            float getVoltage();
    };

#endif
