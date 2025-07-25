#ifndef TEMPERATURE_HTTP_DATA_SENDER_H
    #define TEMPERATURE_HTTP_DATA_SENDER_H

    #include "infrastructure/web/WebClient.h"
    #include "application/WaterLevelConverter.h"
    #include "infrastructure/sensors/DS18B20Sensor.h"
    #include "infrastructure/env.h"
    #include "application/BatteryLevelService.h"

    class HttpDataSender {
        private:
            WaterLevelConverter& waterLevelConverter;
            DS18B20Sensor& temperatureSensor;
            BatteryLevelService& batteryLevelService;
            WebClient& webClient;
            String buildPath(String percentRange, String litersRange, String temperatureStr, String batteryLevelStr);

        public:
            HttpDataSender(
                WaterLevelConverter& waterLevelConverter,
                DS18B20Sensor& temperatureSensor,
                BatteryLevelService& batteryLevelService,
                WebClient& webClient
            );
            void send();
    };

#endif
