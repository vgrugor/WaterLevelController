#ifndef LOAD_MODE_SERVICE_H
    #define LOAD_MODE_SERVICE_H

    #include <Arduino.h>

    class LoadModeService {
        private:
            unsigned int loadModeButtonPin;
            bool isLoadInWaterIntakeMode;

        public:
            LoadModeService(unsigned int loadModeButtonPin);
            void identifyMode();
            bool isWaterIntakeMode();
            bool isDataSendMode();
    };

#endif
