#include "presentation/observers/BuzzerObserver.h"

BuzzerObserver::BuzzerObserver(BuzzerActuator buzzerActuator) : buzzerActuator(buzzerActuator) {}

void BuzzerObserver::update(EventType eventType, const String& message) {
    switch (eventType) {
        //WIFI events
        case EventType::WIFI_START_CONNECT: 
            this->buzzerActuator.setState(HIGH);
            delay(1000);
            this->buzzerActuator.setState(LOW);
            delay(1000);
            break;
        case EventType::WIFI_TRY_CONNECT: 
            this->buzzerActuator.setState(HIGH);
            delay(100);
            this->buzzerActuator.setState(LOW);
            delay(100);
            break;
        case EventType::WIFI_CONNECTED: 
            this->buzzerActuator.setState(HIGH);
            delay(500);
            this->buzzerActuator.setState(LOW);
            delay(500);
            this->buzzerActuator.setState(HIGH);
            delay(500);
            this->buzzerActuator.setState(LOW);
            break;
        case EventType::WIFI_RECONNECT: 
            break;

        //temperature events
        case EventType::READ_TEMPERATURE:
            break;
        case EventType::SEND_TEMPERATURE:
            break;

        //water level events
        case EventType::READ_WATER_LEVEL:
            this->buzzerActuator.setState(HIGH);
            delay(100);
            this->buzzerActuator.setState(LOW);
            delay(100);
            break;
        case EventType::SEND_WATER_LEVEL:
            this->buzzerActuator.setState(HIGH);
            delay(100);
            this->buzzerActuator.setState(LOW);
            delay(100);
            break;
    }
}
