#include "infrastructure/sleep/DeepSleepManager.h"

void DeepSleepManager::sleepForMinutes(uint32_t minutes) {
    delay(DeepSleepManager::DELAY_BEFORE_SLEEP);
    ESP.deepSleep(minutes * 60 * 1000000);
}
