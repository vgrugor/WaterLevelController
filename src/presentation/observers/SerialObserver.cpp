#include "presentation/observers/SerialObserver.h"

void SerialObserver::update(EventType eventType, const String& message) {
    String text;

    switch (eventType) {
        //load mode events
        case EventType::WATER_INTAKE_MODE_ACTIVATED: text = "Water intake mode activated"; break;
        case EventType::DATA_SEND_MODE_ACTIVATED: text = "Data send mode activated"; break;

        //water intake mode events
        case EventType::WATER_INTAKE_MODE_CHANGE_LEVEL: text = "Water intake level changed to " + message + "%"; break;

        //WIFI events
        case EventType::WIFI_START_CONNECT: text = "Start connecting to WiFi"; break;
        case EventType::WIFI_TRY_CONNECT: text = "."; break;
        case EventType::WIFI_CONNECTED: text = "WiFi connected"; break;
        case EventType::WIFI_RECONNECT: text = "WiFi reconnect"; break;
        
        //temperature events
        case EventType::READ_TEMPERATURE: text = "Read temperature data. Temperature: " + message + "°C"; break;
        case EventType::SEND_TEMPERATURE: text = "Send temperature data. Temperature: " + message + "°C"; break;

        //water level events
        case EventType::READ_WATER_LEVEL: text = "Read water level. Level: " + message + "%"; break;
        case EventType::SEND_WATER_LEVEL: text = "Send water level: " + message; break;

        //battery level events
        case EventType::READ_BATTERY_LEVEL: text = "Read battery level. Level: " + message; break;
        case EventType::SEND_BATTERY_LEVEL: text = "Send battery level. Level: " + message; break;

        //data send events
        case EventType::ALL_DATA_SEND: text = "All data send!"; break;
    }

    Serial.println(text);
}
