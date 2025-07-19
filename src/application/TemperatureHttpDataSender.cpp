#include "application/TemperatureHttpDataSender.h"

TemperatureHttpDataSender::TemperatureHttpDataSender(
    DS18B20Sensor& temperatureSensor,
    WebClient& webClient
)
    : temperatureSensor(temperatureSensor),
    webClient(webClient)
{
}

void TemperatureHttpDataSender::send() 
{
    float temperature = this->temperatureSensor.readValue();
    String temperatureStr = String(temperature, 2);

    String serverWaterTemperaturePath =  WATER_TEMPERATURE_SERVER_URL
        + "?" 
        + WATER_TEMPERATURE_PARAM_NAME 
        + "=" 
        + temperatureStr;

    this->webClient.get(serverWaterTemperaturePath);

    delay(100);
}
