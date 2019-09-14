#pragma once
#include <Arduino.h>
#include <stdint.h>
#include <basic_motor.hpp>
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
  BasicMotor m_lowerActuator;
  BasicMotor m_upperActuator;
  MC33926 m_turntableMotor;
  MC33926 m_grasperRotationMotor;
  MC33926 m_grasperXAxisMotor;
  MC33926 m_grasperYAxisMotor;
};