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
    int percentWaterLevel = this->waterLevelConverter.getPercent();
    String percentWaterLevelStr = String(percentWaterLevel);
    delay(100);

    String litersRangeWaterLevel = this->waterLevelConverter.getLitersRange();
    delay(100);

    float temperature = this->temperatureSensor.readValue();
    String temperatureStr = String(temperature, 2);
    delay(100);

    float batteryVoltage = this->batteryLevelService.getVoltage();
    String batteryVoltageStr = String(batteryVoltage, 2);
    delay(100);

    float batteryPercent = this->batteryLevelService.getPercent();
    String batteryPercentStr = String(batteryPercent, 0);
    delay(100);

    this->webClient.get(
        this->buildPath(percentWaterLevelStr, litersRangeWaterLevel, temperatureStr, batteryVoltageStr, batteryPercentStr)
    );

    String waterLevel = percentWaterLevelStr + "% and " + litersRangeWaterLevel + "l";
    EventNotifier::getInstance().notifyObservers(EventType::SEND_WATER_LEVEL, waterLevel);

    EventNotifier::getInstance().notifyObservers(EventType::SEND_TEMPERATURE, temperatureStr);

    String batteryLevel = batteryPercentStr + "% and " + batteryVoltageStr + "v";
    EventNotifier::getInstance().notifyObservers(EventType::SEND_BATTERY_LEVEL, batteryLevel);

    EventNotifier::getInstance().notifyObservers(EventType::ALL_DATA_SEND);
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
