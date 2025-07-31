#include <Arduino.h>
#include <PCF8574.h>
#include <Wire.h>
#include "infrastructure/sensors/PCF8574Input.h"
#include "application/WaterLevelConverter.h"
#include "infrastructure/env.h"
#include "infrastructure/wifi/WiFiManager.h"
#include "infrastructure/sensors/DS18B20Sensor.h"
#include "infrastructure/web/WebClient.h"
#include "infrastructure/actuators/BuzzerActuator.h"
#include "presentation/observers/BuzzerObserver.h"
#include "presentation/observers/SerialObserver.h"
#include "infrastructure/sensors/BatteryLevelSensor.h"
#include "application/HttpDataSender.h"
#include "infrastructure/actuators/WaterCommonPinActuator.h"
#include "infrastructure/actuators/BatteryLevelSensorActuator.h"
#include "application/BatteryLevelService.h"
#include "infrastructure/sleep/DeepSleepManager.h"
#include "application/WaterLitersRangeCalculator.h"
#include "application/LoadModeService.h"
#include "application/WaterIntakeService.h"

LoadModeService loadModeService(LOAD_MODE_BUTTON_PIN);

WaterCommonPinActuator waterCommonPinActuator(WATER_COMMON_PIN);

PCF8574 pcf(0x27);

PCF8574Input waterSensor1(pcf, 0);
PCF8574Input waterSensor2(pcf, 1);
PCF8574Input waterSensor3(pcf, 2);
PCF8574Input waterSensor4(pcf, 4);
PCF8574Input waterSensor5(pcf, 5);
PCF8574Input waterSensor6(pcf, 6);
PCF8574Input waterSensor7(pcf, 7);

WaterLitersRangeCalculator waterLitersRangeCalculator(WATER_VOLUME);

WaterLevelConverter waterLevelConverter(
	waterSensor1, 
	waterSensor2, 
	waterSensor3, 
	waterSensor4, 
	waterSensor5, 
	waterSensor6, 
	waterSensor7,
	waterCommonPinActuator,
	waterLitersRangeCalculator
);

DeepSleepManager deepSleepManager;

WaterIntakeService waterIntakeService(waterLevelConverter, deepSleepManager, WATER_INTAKE_UPDATE_INTERVAL_MILLI_SECONDS);

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN);

BatteryLevelSensorActuator batteryLevelSensorActuator(BATTERY_LEVEL_SENSOR_ACTUATOR_PIN);
BatteryLevelSensor batteryLevelSensor(A0);
BatteryLevelService batteryLevelService(batteryLevelSensorActuator, batteryLevelSensor);

WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET, deepSleepManager);

WebClient webClient;

HttpDataSender httpDataSender(waterLevelConverter, temperatureSensor, batteryLevelService, webClient);

BuzzerActuator buzzerActuator(BUZZER_PIN);
BuzzerObserver buzzerObserver(buzzerActuator);
SerialObserver serialObserver;
EventNotifier& eventNotifier = EventNotifier::getInstance();

void setup() {
	Serial.begin(115200);

	Wire.begin();
	pcf.begin();

	eventNotifier.addObserver(&buzzerObserver);
    eventNotifier.addObserver(&serialObserver);

	loadModeService.identifyMode();

	if (loadModeService.isWaterIntakeMode()) {
		wifiManager.disable();
	} else {
		wifiManager.connect();

		httpDataSender.send();

		wifiManager.disable();

		deepSleepManager.sleepForMinutes(DEEP_SLEEP_TIME_MINUTES);
	}
}

void loop() {
	if (loadModeService.isWaterIntakeMode()) {
		waterIntakeService.update();
	}
}
