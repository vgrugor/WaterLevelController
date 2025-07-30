#include "application/WaterIntakeService.h"

WaterIntakeService::WaterIntakeService(
    WaterLevelConverter& waterLevelConverter
) : waterLevelConverter(waterLevelConverter)
{
}

void WaterIntakeService::begin() 
{
    this->previousLevel = this->waterLevelConverter.getPercent();

    EventNotifier::getInstance().notifyObservers(
        EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
        String(this->previousLevel)
    );
}

void WaterIntakeService::update() 
{
    int currentLevel = this->waterLevelConverter.getPercent();

    if (currentLevel != this->previousLevel) {
        this->previousLevel = currentLevel;

        EventNotifier::getInstance().notifyObservers(
            EventType::WATER_INTAKE_MODE_CHANGE_LEVEL, 
            String(currentLevel)
        );
    }

    delay(2000);
}
