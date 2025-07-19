#include "presentation/observers/SerialObserver.h"

void SerialObserver::update(EventType eventType, const String& message) {
    String text;

    switch (eventType) {
        //WIFI events
        case EventType::WIFI_START_CONNECT: text = "Start connecting to WiFi"; break;
        case EventType::WIFI_TRY_CONNECT: text = "."; break;
        case EventType::WIFI_CONNECTED: text = "WiFi connected"; break;
        case EventType::WIFI_RECONNECT: text = "WiFi reconnect"; break;
        
        //temperature events
        case EventType::READ_TEMPERATURE: text = "Read temperature data. Temperature: " + message + "°C"; break;
        case EventType::SEND_TEMPERATURE: text = "Send temperature data. Temperature: " + message + "°C"; break;

        //water level events
        case EventType::READ_WATER_LEVEL: text = "Read water level. Level: " + message + "°C"; break;
        case EventType::SEND_WATER_LEVEL: text = "Send water level. Level: " + message + "°C"; break;
    }

    Serial.println(text);
}
