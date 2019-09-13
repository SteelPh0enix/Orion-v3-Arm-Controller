#pragma once
#include <Arduino.h>
#include <cstdint>
#include <mc33926.hpp>
#include <basic_motor.hpp>

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
  BasicMotor m_lowerActuator;
  BasicMotor m_upperActuator;
  MC33926 m_turntableMotor;
  MC33926 m_grasperRotationMotor;
  MC33926 m_grasperXAxisMotor;
  MC33926 m_grasperYAxisMotor;
};