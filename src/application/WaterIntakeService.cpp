#include "application/WaterIntakeService.h"

WaterIntakeService::WaterIntakeService(
    WaterLevelConverter& waterLevelConverter, 
    unsigned long updateInterval
) : waterLevelConverter(waterLevelConverter),
    updateInterval(updateInterval)
{
}

void WaterIntakeService::update() 
{
    this->initCurrentLevel();

    unsigned long currentTime = millis();

    if ((unsigned long) (currentTime - this->lastUpdateTime) >= this->updateInterval) {
        int currentLevel = this->waterLevelConverter.getPercent();

        if (currentLevel != this->previousLevel) {
            this->previousLevel = currentLevel;

            EventNotifier::getInstance().notifyObservers(
                EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
                String(currentLevel)
            );
        }

        this->lastUpdateTime = currentTime;
    }
}

void WaterIntakeService::initCurrentLevel()
{
    if (this->previousLevel == std::numeric_limits<int>::min()) {
        this->previousLevel = this->waterLevelConverter.getPercent();

        EventNotifier::getInstance().notifyObservers(
            EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
            String(this->previousLevel)
        );
    }
}
