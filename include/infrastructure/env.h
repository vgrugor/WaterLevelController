// env.h
#ifndef ENV_H
    #define ENV_H

    #include "Arduino.h"

    extern const char* WIFI_SSID;
    extern const char* WIFI_PASSWORD;
    extern const char* WIFI_IP;
    extern const char* WIFI_GATEWAY;
    extern const char* WIFI_SUBNET;
    extern const unsigned int MAX_COUNT_WIFI_CONNECT_ATTEMPTS;

    extern const unsigned int WATER_VOLUME;
    extern const unsigned int COUNT_BATTERY_LEVEL_READ;

    extern const unsigned int WATER_SENSOR_1_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_2_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_3_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_4_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_5_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_6_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_7_LEVEL_PERCENT;
    extern const unsigned int WATER_MIN_LEVEL_PERCENT;

    extern const int WATER_COMMON_PIN;
    extern const int BATTERY_LEVEL_SENSOR_ACTUATOR_PIN;
    extern const unsigned char TEMPERATURE_SENSOR_PIN;
    extern const int LOAD_MODE_BUTTON_PIN;
    extern const int BUZZER_PIN;

    extern const float BATTERY_MAX_LEVEL;
    extern const float BATTERY_MIN_LEVEL;
    extern const float V_REF;
    extern const float BATTERY_LEVEL_CORRECT_COEFFICIENT;

    extern const String SERVER_IP;
    extern const String SERVER_PORT;

    extern const String SHOWER_UPDATE_SERVER_URI;
    extern const String SHOWER_WATER_LEVEL_PERCENT_PARAM_NAME;
    extern const String SHOWER_WATER_LEVEL_LITER_PARAM_NAME;
    extern const String SHOWER_WATER_TEMPERATURE_PARAM_NAME;
    extern const String SHOWER_BATTERY_VOLTAGE_PARAM_NAME;
    extern const String SHOWER_BATTERY_PERCENT_PARAM_NAME;
    extern const String SHOWER_UPDATE_SERVER_URL;

    extern const unsigned int DEEP_SLEEP_TIME_MINUTES;

#endif // ENV_H
