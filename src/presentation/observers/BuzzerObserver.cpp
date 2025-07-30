#include "presentation/observers/BuzzerObserver.h"

BuzzerObserver::BuzzerObserver(BuzzerActuator buzzerActuator) : buzzerActuator(buzzerActuator) {}

void BuzzerObserver::update(EventType eventType, const String& message) {
    unsigned int delayMillis;

    switch (eventType) {
        //load mode events
        case EventType::WATER_INTAKE_MODE_ACTIVATED: 
            this->buzzerActuator.setState(HIGH);
            delay(4000);
            this->buzzerActuator.setState(LOW);
            delay(1000);
            break;
        case EventType::DATA_SEND_MODE_ACTIVATED: 
            delayMillis = 100;

            for (int i = 1; i <= 3; i++) {
                this->buzzerActuator.setState(HIGH);
                delay(delayMillis);
                this->buzzerActuator.setState(LOW);
                delay(delayMillis);
            }
            break;

        //water intake mode events
        case EventType::WATER_INTAKE_MODE_CHANGE_LEVEL: {
            int level = message.toInt();
            int countSignal;

            if (level == WATER_SENSOR_1_LEVEL_PERCENT) {
                countSignal = 1;
            } else if (level == WATER_SENSOR_2_LEVEL_PERCENT) {
                countSignal = 2;
            } else if (level == WATER_SENSOR_3_LEVEL_PERCENT) {
                countSignal = 3;
            } else if (level == WATER_SENSOR_4_LEVEL_PERCENT) {
                countSignal = 4;
            } else if (level == WATER_SENSOR_5_LEVEL_PERCENT) {
                countSignal = 5;
            } else if (level == WATER_SENSOR_6_LEVEL_PERCENT) {
                countSignal = 6;
            } else if (level == WATER_SENSOR_7_LEVEL_PERCENT) {
                countSignal = 7;
            } else {
                countSignal = 0;
            }

            if (countSignal > 0) {
                delayMillis = 1000;

                for (int i = 1; i <= countSignal; i++) {
                    this->buzzerActuator.setState(HIGH);
                    delay(delayMillis);
                    this->buzzerActuator.setState(LOW);
                    delay(delayMillis);
                }
            } else {
                delayMillis = 10;

                for (int i = 1; i <= 10; i++) {
                    this->buzzerActuator.setState(HIGH);
                    delay(delayMillis);
                    this->buzzerActuator.setState(LOW);
                    delay(delayMillis);
                }
            }

            break;
        }

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
            delay(500);
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
            break;
        case EventType::SEND_WATER_LEVEL:
            break;

        //battery level events
        case EventType::READ_BATTERY_LEVEL:
            break;
        case EventType::SEND_BATTERY_LEVEL:
            break;

        //data send events
        case EventType::ALL_DATA_SEND:
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            this->buzzerActuator.setState(HIGH);
            delay(50);
            this->buzzerActuator.setState(LOW);
            delay(50);
            break;
    }
}
