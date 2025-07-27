#include "infrastructure/wifi/WiFiManager.h"

WiFiManager::WiFiManager(
    const char* ssid, 
    const char* password, 
    const char* ip, 
    const char* gateway, 
    const char* subnet,
    DeepSleepManager& deepSleepManager
) : 
    ssid(ssid), 
    password(password), 
    ip(ip), 
    gateway(gateway), 
    subnet(subnet),
    deepSleepManager(deepSleepManager)
{
}

void WiFiManager::connect() {
    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;

    ip.fromString(this->ip);
    gateway.fromString(this->gateway);
    subnet.fromString(this->subnet);

    WiFi.mode(WIFI_STA);
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);

    EventNotifier& eventNotifier = EventNotifier::getInstance();

    eventNotifier.notifyObservers(EventType::WIFI_START_CONNECT);

    unsigned int attempts = 0;

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        eventNotifier.notifyObservers(EventType::WIFI_TRY_CONNECT);
        attempts++;

        if (attempts > MAX_COUNT_WIFI_CONNECT_ATTEMPTS) {
            attempts = 0;
            this->deepSleepManager.sleepForMinutes(DEEP_SLEEP_TIME_MINUTES);
        }
    }

    eventNotifier.notifyObservers(EventType::WIFI_CONNECTED);
}

void WiFiManager::reconnect() {
    if (!isConnected()) {
        EventNotifier::getInstance().notifyObservers(EventType::WIFI_RECONNECT);
        this->connect();
    }
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

String WiFiManager::getIPAddress() {
    return WiFi.localIP().toString();
}
