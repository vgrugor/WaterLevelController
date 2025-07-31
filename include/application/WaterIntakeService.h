#ifndef WATER_INTAKE_SERVICE_CONVERTER_H
    #define WATER_INTAKE_SERVICE_CONVERTER_H

    #include "application/WaterLevelConverter.h"
    #include "presentation/EventNotifier.h"
    #include <limits>

    class WaterIntakeService {
        private:
            WaterLevelConverter& waterLevelConverter;
            int previousLevel = std::numeric_limits<int>::min();
            unsigned long lastUpdateTime = 0;
            unsigned long updateInterval;
            void initCurrentLevel();

        public:
            WaterIntakeService(WaterLevelConverter& waterLevelConverter, unsigned long updateInterval);
            void update();
    };

#endif
