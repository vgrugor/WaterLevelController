#include "application/HttpDataSender.h"

HttpDataSender::HttpDataSender(
    WaterLevelConverter& waterLevelConverter,
    DS18B20Sensor& temperatureSensor,
    BatteryLevelService& batteryLevelService,
    WebClient& webClient
)
    : waterLevelConverter(waterLevelConverter),
    temperatureSensor(temperatureSensor),
    batteryLevelService(batteryLevelService),
    webClient(webClient)
{
}

void HttpDataSender::send() 
{
    String percentRange = this->waterLevelConverter.getPercentRange();
    delay(100);

    String litersRange = this->waterLevelConverter.getLitersRange();
    delay(100);

    float temperature = this->temperatureSensor.readValue();
    String temperatureStr = String(temperature, 2);
    delay(100);

    float batteryVoltage = this->batteryLevelService.getVoltage();
    String batteryVoltageStr = String(batteryVoltage);
    delay(100);

    float batteryPercent = this->batteryLevelService.getPercent();
    String batteryPercentStr = String(batteryPercent);
    delay(100);

    this->webClient.get(
        this->buildPath(percentRange, litersRange, temperatureStr, batteryVoltageStr, batteryPercentStr)
    );
}

String HttpDataSender::buildPath(
    String waterLevelPercentRange, 
    String waterLevelLitersRange, 
    String temperatureStr, 
    String batteryVoltageStr,
    String batteryPercentStr
) {
    return SHOWER_UPDATE_SERVER_URL
        + "?" 
        + SHOWER_WATER_LEVEL_PERCENT_PARAM_NAME 
        + "=" 
        + waterLevelPercentRange
        + "?" 
        + SHOWER_WATER_LEVEL_LITER_PARAM_NAME 
        + "=" 
        + waterLevelLitersRange
        + "?" 
        + SHOWER_WATER_TEMPERATURE_PARAM_NAME 
        + "=" 
        + temperatureStr
        + "?" 
        + SHOWER_BATTERY_VOLTAGE_PARAM_NAME 
        + "=" 
        + batteryVoltageStr;
        + "?" 
        + SHOWER_BATTERY_PERCENT_PARAM_NAME 
        + "=" 
        + batteryPercentStr;
}
