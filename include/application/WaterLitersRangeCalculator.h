#ifndef WATER_LITERS_RANGE_CALCULATOR_H
    #define WATER_LITERS_RANGE_CALCULATOR_H

    #include <Arduino.h>
    #include <vector>
    #include "infrastructure/env.h"

    struct WaterLevelStep {
        unsigned int percent;
    };

    class WaterLitersRangeCalculator {
        public:
            WaterLitersRangeCalculator(unsigned int fullVolumeLiters);
            String getRangeForPercent(unsigned int percent);

        private:
            unsigned int fullVolume;
            std::vector<WaterLevelStep> sensorThresholds;

            float percentToLiters(unsigned int percent);
    };

#endif
