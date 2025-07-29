#ifndef LOAD_MODE_SERVICE_H
    #define LOAD_MODE_SERVICE_H

    #include <Arduino.h>
    #include "presentation/EventNotifier.h"

    class LoadModeService {
        private:
            unsigned int loadModeButtonPin;
            bool isLoadInWaterIntakeMode;

        public:
            LoadModeService(unsigned int loadModeButtonPin);
            void identifyMode();
            bool isWaterIntakeMode();
    };

#endif
