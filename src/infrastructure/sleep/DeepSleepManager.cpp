#include "infrastructure/sleep/DeepSleepManager.h"

void DeepSleepManager::sleepForMinutes(uint32_t minutes) {
    EventNotifier::getInstance().notifyObservers(EventType::GO_TO_SLEEP);

    delay(DeepSleepManager::DELAY_BEFORE_SLEEP);

    ESP.deepSleep(minutes * 60 * 1000000);
}

void DeepSleepManager::sleepAndReload() {
    EventNotifier::getInstance().notifyObservers(EventType::GO_TO_SLEEP);

    delay(DeepSleepManager::DELAY_BEFORE_SLEEP);

    ESP.deepSleep(1 * 1000000);
}
