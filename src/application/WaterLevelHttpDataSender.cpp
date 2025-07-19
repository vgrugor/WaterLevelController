#include "application/WaterLevelHttpDataSender.h"

WaterLevelHttpDataSender::WaterLevelHttpDataSender(
    WaterLevelConverter& waterLevelConverter,
    WebClient& webClient
)
    : waterLevelConverter(waterLevelConverter),
    webClient(webClient)
{
}

void WaterLevelHttpDataSender::send() 
{
    this->sendPercent();
    this->sendLiter();
}

void WaterLevelHttpDataSender::sendPercent() 
{
    String percentRange = this->waterLevelConverter.getPercentRange();

    String serverWaterLevelPercentPath =  WATER_PERCENT_SERVER_URL
        + "?" 
        + WATER_LEVEL_PERCENT_PARAM_NAME 
        + "=" 
        + percentRange;

    this->webClient.get(serverWaterLevelPercentPath);

    delay(100);
}

void WaterLevelHttpDataSender::sendLiter() 
{
    String litersRange = this->waterLevelConverter.getLitersRange();

    String serverWaterLevelLiterPath = WATER_LITER_SERVER_URL 
        + "?" 
        + WATER_LEVEL_LITER_PARAM_NAME 
        + "=" 
        + litersRange;

    this->webClient.get(serverWaterLevelLiterPath);

    delay(100);
}
