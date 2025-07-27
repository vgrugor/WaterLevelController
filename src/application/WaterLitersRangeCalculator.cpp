#include "application/WaterLitersRangeCalculator.h"

WaterLitersRangeCalculator::WaterLitersRangeCalculator(unsigned int fullVolumeLiters)
    : fullVolume(fullVolumeLiters)
{
    sensorThresholds.push_back({WATER_SENSOR_1_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_2_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_3_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_4_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_5_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_6_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_SENSOR_7_LEVEL_PERCENT});
    sensorThresholds.push_back({WATER_MIN_LEVEL_PERCENT});
}

float WaterLitersRangeCalculator::percentToLiters(unsigned int percent) {
    return (this->fullVolume * percent) / 100.0;
}

String WaterLitersRangeCalculator::getRangeForPercent(unsigned int percent) {
    for (size_t i = 0; i < sensorThresholds.size() - 1; ++i) {
        uint8_t upper = sensorThresholds[i].percent;
        uint8_t lower = sensorThresholds[i + 1].percent;

        if (percent >= lower && percent < upper) {
            int minLiters = round(percentToLiters(lower));
            int maxLiters = round(percentToLiters(upper)) - 1;
            return String(minLiters) + "-" + String(maxLiters);
        }

        if (percent == 100) {
            return String(fullVolume);
        }
    }

    return "<" + String(round(percentToLiters(sensorThresholds.back().percent)));
}
