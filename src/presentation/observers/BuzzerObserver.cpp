#include "presentation/observers/BuzzerObserver.h"

BuzzerObserver::BuzzerObserver(BuzzerActuator buzzerActuator) : buzzerActuator(buzzerActuator) {}

void BuzzerObserver::update(EventType eventType, const String& message) {
    unsigned int delayMillis;

    switch (eventType) {
        //load mode events
        case EventType::WATER_INTAKE_MODE_ACTIVATED: this->signal(1, 4000, 1000); break;
        case EventType::DATA_SEND_MODE_ACTIVATED: this->signal(3, 100, 100); break;
        case EventType::GO_TO_SLEEP: break;

        //water intake mode events
        case EventType::WATER_INTAKE_MODE_CHANGE_LEVEL: {
            int level = message.toInt();
            int countSignal;

            if (level == WATER_SENSOR_1_LEVEL_LITER) {
                countSignal = 1;
            } else if (level == WATER_SENSOR_2_LEVEL_LITER) {
                countSignal = 2;
            } else if (level == WATER_SENSOR_3_LEVEL_LITER) {
                countSignal = 3;
            } else if (level == WATER_SENSOR_4_LEVEL_LITER) {
                countSignal = 4;
            } else if (level == WATER_SENSOR_5_LEVEL_LITER) {
                countSignal = 5;
            } else if (level == WATER_SENSOR_6_LEVEL_LITER) {
                countSignal = 6;
            } else if (level == WATER_SENSOR_7_LEVEL_LITER) {
                countSignal = 7;
            } else {
                countSignal = 0;
            }

            if (countSignal > 0) {
                delayMillis = 1000;
                this->signal(countSignal, 1000, 1000);
            } else {
                delayMillis = 10;
                this->signal(10, 10, 10);
            }

            break;
        }

        //WIFI events
        case EventType::WIFI_START_CONNECT: this->signal(1, 1000, 1000); break;
        case EventType::WIFI_TRY_CONNECT: this->signal(1, 100, 100); break;
        case EventType::WIFI_CONNECTED: this->signal(2, 500, 500); break;
        case EventType::WIFI_RECONNECT: break;

        //temperature events
        case EventType::READ_TEMPERATURE: break;
        case EventType::SEND_TEMPERATURE: break;

        //water level events
        case EventType::READ_WATER_LEVEL: break;
        case EventType::SEND_WATER_LEVEL: break;

        //battery level events
        case EventType::READ_BATTERY_LEVEL: break;
        case EventType::SEND_BATTERY_LEVEL: break;

        //data send events
        case EventType::ALL_DATA_SEND: this->signal(10, 50, 50); break;
    }
}

void BuzzerObserver::signal(int count, int onTime, int offTime) {
    for (int i = 0; i < count; ++i) {
        delay(offTime);
        this->buzzerActuator.setState(HIGH);
        delay(onTime);
        this->buzzerActuator.setState(LOW);
        delay(offTime);
    }
}
