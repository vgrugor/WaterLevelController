#include "application/LoadModeService.h"

LoadModeService::LoadModeService(unsigned int loadModeButtonPin)
    : loadModeButtonPin(loadModeButtonPin)
{
    pinMode(loadModeButtonPin, INPUT);
}

void LoadModeService::identifyMode() 
{
    this->isLoadInWaterIntakeMode = !digitalRead(this->loadModeButtonPin);

    if (this->isWaterIntakeMode()) {
        EventNotifier::getInstance().notifyObservers(EventType::WATER_INTAKE_MODE_ACTIVATED);
    } else {
        EventNotifier::getInstance().notifyObservers(EventType::DATA_SEND_MODE_ACTIVATED);
    }
}

bool LoadModeService::isWaterIntakeMode() 
{
    return this->isLoadInWaterIntakeMode;
}
