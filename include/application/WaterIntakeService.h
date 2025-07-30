#ifndef WATER_INTAKE_SERVICE_CONVERTER_H
    #define WATER_INTAKE_SERVICE_CONVERTER_H

    #include "application/WaterLevelConverter.h"
    #include "presentation/EventNotifier.h"

    class WaterIntakeService {
        private:
            WaterLevelConverter& waterLevelConverter;
            int previousLevel;

        public:
            WaterIntakeService(
                WaterLevelConverter& waterLevelConverter
            );
            void begin();
            void update();
    };

#endif
