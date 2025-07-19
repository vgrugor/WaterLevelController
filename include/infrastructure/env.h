// env.h
#ifndef ENV_H
    #define ENV_H

    #include "Arduino.h"

    extern const char* OTA_HOSTNAME;
    extern const char* OTA_PASSWORD;

    extern const char* WIFI_SSID;
    extern const char* WIFI_PASSWORD;
    extern const char* WIFI_IP;
    extern const char* WIFI_GATEWAY;
    extern const char* WIFI_SUBNET;

    extern const unsigned int WATER_VOLUME;

    extern const unsigned int WATER_SENSOR_1_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_2_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_3_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_4_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_5_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_6_LEVEL_PERCENT;
    extern const unsigned int WATER_SENSOR_7_LEVEL_PERCENT;
    extern const unsigned int WATER_MIN_LEVEL_PERCENT;

    extern const String WATER_SENSOR_1_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_2_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_3_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_4_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_5_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_6_LEVEL_PERCENT_RANGE;
    extern const String WATER_SENSOR_7_LEVEL_PERCENT_RANGE;
    extern const String WATER_MIN_LEVEL_PERCENT_RANGE;

    extern const String WATER_SENSOR_1_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_2_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_3_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_4_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_5_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_6_LEVEL_LITER_RANGE;
    extern const String WATER_SENSOR_7_LEVEL_LITER_RANGE;
    extern const String WATER_MIN_LEVEL_LITER_RANGE;

    //extern const int GREEN_LED_PIN;
    extern const int BUZZER_PIN;

    //extern const int BOARD_LED;

    extern const unsigned char TEMPERATURE_SENSOR_PIN;
    extern const String SERVER_IP;
    extern const String SERVER_PORT;

    extern const String WATER_LEVEL_PERCENT_SERVER_URI;
    extern const String WATER_LEVEL_LITER_SERVER_URI;
    extern const String WATER_TEMPERATURE_SERVER_URI;

    extern const String WATER_LEVEL_PERCENT_PARAM_NAME;
    extern const String WATER_LEVEL_LITER_PARAM_NAME;
    extern const String WATER_TEMPERATURE_PARAM_NAME;

    extern const String WATER_PERCENT_SERVER_URL;
    extern const String WATER_LITER_SERVER_URL;
    extern const String WATER_TEMPERATURE_SERVER_URL;

#endif // ENV_H
