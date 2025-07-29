#ifndef EVENT_TYPE_H
    #define EVENT_TYPE_H

    enum class EventType {
        //load mode events
        WATER_INTAKE_MODE_ACTIVATED,
        DATA_SEND_MODE_ACTIVATED,

        //WiFi events
        WIFI_START_CONNECT,
        WIFI_TRY_CONNECT,
        WIFI_CONNECTED,
        WIFI_RECONNECT,
        
        //temperature events
        READ_TEMPERATURE,
        SEND_TEMPERATURE,

        //water level events
        READ_WATER_LEVEL,
        SEND_WATER_LEVEL,

        //battery level events
        READ_BATTERY_LEVEL,
        SEND_BATTERY_LEVEL,

        //data send events
        ALL_DATA_SEND
    };

#endif
