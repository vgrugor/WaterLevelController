#include "application/WaterIntakeService.h"

WaterIntakeService::WaterIntakeService(
    WaterLevelConverter& waterLevelConverter, 
    DeepSleepManager& deepSleepManager,
    unsigned long updateIntervalMilliSeconds
) : waterLevelConverter(waterLevelConverter),
    deepSleepManager(deepSleepManager),
    updateIntervalMilliSeconds(updateIntervalMilliSeconds)
{
}

void WaterIntakeService::update() 
{
    this->init();

    unsigned long currentTime = millis();

    if ((unsigned long) (currentTime - this->lastUpdateTime) >= this->updateIntervalMilliSeconds) {
        int currentLevel = this->waterLevelConverter.getLiter();

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
            || currentLevel == WATER_SENSOR_7_LEVEL_LITER
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
        this->countReadBeforeGoToSleep = (WATER_INTAKE_INTERVAL_GO_TO_SLEEP_IF_LEVEL_NOT_CHANGED_MINUTES * 60 * 1000) / WATER_INTAKE_UPDATE_INTERVAL_MILLI_SECONDS;

        this->previousLevel = this->waterLevelConverter.getLiter();

        EventNotifier::getInstance().notifyObservers(
            EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
            String(this->previousLevel)
        );
    }
}
