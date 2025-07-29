#include "application/LoadModeService.h"

LoadModeService::LoadModeService(unsigned int loadModeButtonPin)
    : loadModeButtonPin(loadModeButtonPin)
{
    pinMode(loadModeButtonPin, INPUT);
}

void LoadModeService::identifyMode() 
{
    this->isLoadInWaterIntakeMode = !digitalRead(this->loadModeButtonPin);
}

bool LoadModeService::isWaterIntakeMode() 
{
    return this->isLoadInWaterIntakeMode;
}

bool LoadModeService::isDataSendMode() 
{
    return !this->isLoadInWaterIntakeMode;
}
