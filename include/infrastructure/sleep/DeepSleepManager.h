#ifndef DEEP_SLEEP_MANAGER_H
    #define DEEP_SLEEP_MANAGER_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include "presentation/EventNotifier.h"

    class DeepSleepManager {
        private:
            const unsigned int DELAY_BEFORE_SLEEP = 1000;

        public:
            void sleepForMinutes(uint32_t minutes);
            void sleepAndReload();
    };

#endif
