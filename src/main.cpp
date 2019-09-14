#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <arm.hpp>
#include <config.hpp>

char jsonBuffer[Config::JsonBufferSize]{};
ArduinoJson::StaticJsonDocument<Config::JsonBufferSize> jsonDoc;
OrionArm arm;

void setup() {
  Serial.begin(9600);
  arm.initialize();
}

void loop() {
  if (Serial.available()) {
    Serial.readBytesUntil('\n', jsonBuffer, Config::JsonBufferSize);
    // Serial.println(jsonBuffer);
    jsonDoc.clear();
    auto deserializationResult =
        ArduinoJson::deserializeJson(jsonDoc, jsonBuffer);
    if (deserializationResult == ArduinoJson::DeserializationError::Ok) {
      arm.setMotorPower(OrionArm::Motor::GrasperRotation,
                        jsonDoc[Config::Json::GrasperRotationPowerKey]);
      arm.setMotorPower(OrionArm::Motor::GrasperX,
                        jsonDoc[Config::Json::GrasperXAxisPowerKey]);
      arm.setMotorPower(OrionArm::Motor::GrasperY,
                        jsonDoc[Config::Json::GrasperYAxisPowerKey]);
      arm.setMotorPower(OrionArm::Motor::LowerActuator,
                        jsonDoc[Config::Json::LowerActuatorPowerKey]);
      arm.setMotorPower(OrionArm::Motor::Turntable,
                        jsonDoc[Config::Json::TurntablePowerKey]);
      arm.setMotorPower(OrionArm::Motor::UpperActuator,
                        jsonDoc[Config::Json::UpperActuatorPowerKey]);
      jsonDoc.clear();
      jsonDoc[Config::Json::ErrorCodeKey] = 0;
      jsonDoc[Config::Json::ErrorDescriptionKey] = "OK";
    } else {
      arm.stop();
      jsonDoc.clear();
      jsonDoc[Config::Json::ErrorCodeKey] = deserializationResult.code();
      jsonDoc[Config::Json::ErrorDescriptionKey] =
          deserializationResult.c_str();
    }
    ArduinoJson::serializeJson(jsonDoc, Serial);
    Serial.println();
  }
}