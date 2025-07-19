#ifndef WATER_LEVEL_HTTP_DATA_SENDER_H
    #define WATER_LEVEL_HTTP_DATA_SENDER_H

    #include "infrastructure/web/WebClient.h"
    #include "application/WaterLevelConverter.h"
    #include "infrastructure/env.h"

    class WaterLevelHttpDataSender {
        private:
            WaterLevelConverter& waterLevelConverter;
            WebClient& webClient;
            void sendPercent();
            void sendLiter();

        public:
            WaterLevelHttpDataSender(
                WaterLevelConverter& waterLevelConverter,
                WebClient& webClient
            );
            void send();
    };

#endif
