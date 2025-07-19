#ifndef TEMPERATURE_HTTP_DATA_SENDER_H
    #define TEMPERATURE_HTTP_DATA_SENDER_H

    #include "infrastructure/web/WebClient.h"
    #include "application/WaterLevelConverter.h"
    #include "infrastructure/sensors/DS18B20Sensor.h"
    #include "infrastructure/env.h"

    class TemperatureHttpDataSender {
        private:
            DS18B20Sensor& temperatureSensor;
            WebClient& webClient;

        public:
            TemperatureHttpDataSender(
                DS18B20Sensor& temperatureSensor,
                WebClient& webClient
            );
            void send();
    };

#endif
