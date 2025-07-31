#ifndef WATER_INTAKE_SERVICE_CONVERTER_H
    #define WATER_INTAKE_SERVICE_CONVERTER_H

    #include "application/WaterLevelConverter.h"
    #include "presentation/EventNotifier.h"
    #include "infrastructure/sleep/DeepSleepManager.h"
    #include <limits>

    class WaterIntakeService {
        private:
            WaterLevelConverter& waterLevelConverter;
            DeepSleepManager& deepSleepManager;
            int previousLevel = std::numeric_limits<int>::min();
            unsigned long lastUpdateTime = 0;
            unsigned long updateIntervalMilliSeconds;
            unsigned int countRead = 0;
            unsigned int countReadBeforeGoToSleep;
            void init();

        public:
            WaterIntakeService(
                WaterLevelConverter& waterLevelConverter, 
                DeepSleepManager& deepSleepManager,
                unsigned long updateIntervalMilliSeconds
            );
            void update();
    };

#endif
