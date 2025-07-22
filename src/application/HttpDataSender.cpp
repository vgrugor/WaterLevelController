#include "application/HttpDataSender.h"

HttpDataSender::HttpDataSender(
    WaterLevelConverter& waterLevelConverter,
    DS18B20Sensor& temperatureSensor,
    BatteryLevelSensor& batteryLevelSensor,
    WebClient& webClient
)
    : waterLevelConverter(waterLevelConverter),
    temperatureSensor(temperatureSensor),
    batteryLevelSensor(batteryLevelSensor),
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

    float batteryLevel = this->batteryLevelSensor.readValue();
    String batteryLevelStr = String(batteryLevel);
    delay(100);

    this->webClient.get(
        this->buildPath(percentRange, litersRange, temperatureStr, batteryLevelStr)
    );
}

String HttpDataSender::buildPath(
    String percentRange, 
    String litersRange, 
    String temperatureStr, 
    String batteryLevelStr
) {
    return SHOWER_UPDATE_SERVER_URL
        + "?" 
        + SHOWER_WATER_LEVEL_PERCENT_PARAM_NAME 
        + "=" 
        + percentRange
        + "?" 
        + SHOWER_WATER_LEVEL_LITER_PARAM_NAME 
        + "=" 
        + litersRange
        + "?" 
        + SHOWER_WATER_TEMPERATURE_PARAM_NAME 
        + "=" 
        + temperatureStr
        + "?" 
        + SHOWER_BATTERY_LEVEL_PARAM_NAME 
        + "=" 
        + batteryLevelStr;
}
