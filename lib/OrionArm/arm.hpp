#pragma once
#include <Arduino.h>
#include <cstdint>
#include <mc33926.hpp>

class OrionArm {
 public:
  enum class Motor {
    Turntable,
    GrasperRotation,
    GrasperX,
    GrasperY,
    LowerActuator,
    UpperActuator
  };

  OrionArm();

  void initialize();
  void setMotorPower(Motor motor, int power);
  void stop();

 private:
  MC33926 m_turntableMotor;
  MC33926 m_grasperRotationMotor;
  MC33926 m_grasperXAxisMotor;
  MC33926 m_grasperYAxisMotor;
  std::uint8_t m_lowerActuatorPWMPin;
  std::uint8_t m_upperActuatorPWMPin;
};