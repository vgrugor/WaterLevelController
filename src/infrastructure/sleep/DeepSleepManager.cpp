#include "infrastructure/sleep/DeepSleepManager.h"

void DeepSleepManager::sleepForMinutes(uint32_t minutes) {
    delay(DeepSleepManager::DELAY_BEFORE_SLEEP);
    ESP.deepSleep(minutes * 60 * 1000000);
}

void DeepSleepManager::sleepAndReload() {
    delay(DeepSleepManager::DELAY_BEFORE_SLEEP);
    ESP.deepSleep(1 * 1000000);
}
