#include "application/WaterIntakeService.h"

WaterIntakeService::WaterIntakeService(
    WaterLevelConverter& waterLevelConverter, 
    DeepSleepManager& deepSleepManager,
    unsigned long updateInterval
) : waterLevelConverter(waterLevelConverter),
    deepSleepManager(deepSleepManager),
    updateInterval(updateInterval)
{
}

void WaterIntakeService::update() 
{
    this->init();

    unsigned long currentTime = millis();

    if ((unsigned long) (currentTime - this->lastUpdateTime) >= this->updateInterval) {
        int currentLevel = this->waterLevelConverter.getPercent();

        if (currentLevel != this->previousLevel) {
            this->previousLevel = currentLevel;

            EventNotifier::getInstance().notifyObservers(
                EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
                String(currentLevel)
            );
            this->countRead = 0;
        } else {
            this->countRead++;
        }

        this->lastUpdateTime = currentTime;

        if (
            this->countRead > this->countReadBeforeGoToSleep
            || currentLevel == WATER_SENSOR_7_LEVEL_PERCENT
        ) {
            this->countRead = 0;
            this->lastUpdateTime = 0;
            this->deepSleepManager.sleepAndReload();
        }
    }
}

void WaterIntakeService::init()
{
    if (this->previousLevel == std::numeric_limits<int>::min()) {
        this->countReadBeforeGoToSleep = WATER_INTAKE_INTERVAL_GO_TO_SLEEP_IF_LEVEL_NOT_CHANGED_MINUTES * 60 / WATER_INTAKE_UPDATE_INTERVAL_SECONDS;

        this->previousLevel = this->waterLevelConverter.getPercent();

        EventNotifier::getInstance().notifyObservers(
            EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
            String(this->previousLevel)
        );
    }
}
