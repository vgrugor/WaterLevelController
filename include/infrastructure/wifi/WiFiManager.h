#ifndef WIFI_MANAGER_H
    #define WIFI_MANAGER_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include "presentation/EventNotifier.h"
    #include "infrastructure/sleep/DeepSleepManager.h"
    #include "infrastructure/env.h"

    class WiFiManager {
        private:
            const char* ssid;
            const char* password;
            const char* ip;
            const char* gateway;
            const char* subnet;
            DeepSleepManager& deepSleepManager;

        public:
            WiFiManager(
                const char* ssid, 
                const char* password, 
                const char* ip, 
                const char* gateway, 
                const char* subnet, 
                DeepSleepManager& deepSleepManager
            );
            void connect();
            void reconnect();
            bool isConnected();
            String getIPAddress();
    };

#endif // WIFI_MANAGER_H
