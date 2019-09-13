#include "arm.hpp"
#include "../../include/pinout.hpp"

OrionArm::OrionArm() {
  m_turntableMotor.setPins(Pinout::TurntablePWM, Pinout::TurntableDirection,
                           Pinout::TurntableFeedback, Pinout::TurntableDisable,
                           Pinout::TurntableStatusFlag);

  m_grasperRotationMotor.setPins(
      Pinout::GrasperRotationPWM, Pinout::GrasperRotationDirection,
      Pinout::GrasperRotationFeedback, Pinout::GrasperRotationDisable,
      Pinout::GrasperRotationStatusFlag);

  m_grasperXAxisMotor.setPins(Pinout::GrasperXPWM, Pinout::GrasperXDirection,
                              Pinout::GrasperXFeedback, Pinout::GrasperXDisable,
                              Pinout::GrasperXStatusFlag);

  m_grasperYAxisMotor.setPins(Pinout::GrasperYPWM, Pinout::GrasperYDirection,
                              Pinout::GrasperYFeedback, Pinout::GrasperYDisable,
                              Pinout::GrasperYStatusFlag);

  m_lowerActuator.setPins(Pinout::LowerArmActuatorPWM,
                          Pinout::LowerArmActuatorDirectionA,
                          Pinout::LowerArmActuatorDirectionB);

  m_upperActuator.setPins(Pinout::UpperArmActuatorPWM,
                          Pinout::UpperArmActuatorDirectionA,
                          Pinout::UpperArmActuatorDirectionB);
}

void OrionArm::initialize() {
  m_turntableMotor.initialize();
  m_grasperRotationMotor.initialize();
  m_grasperXAxisMotor.initialize();
  m_grasperYAxisMotor.initialize();
  m_lowerActuator.initialize();
  m_upperActuator.initialize();
}

void OrionArm::setMotorPower(OrionArm::Motor motor, int power) {
  switch (motor) {
    case Motor::GrasperRotation:
      m_grasperRotationMotor.setPower(power);
      break;
    case Motor::GrasperX:
      m_grasperXAxisMotor.setPower(power);
      break;
    case Motor::GrasperY:
      m_grasperYAxisMotor.setPower(power);
      break;
    case Motor::LowerActuator:
      m_lowerActuator.setPower(power);
      break;
    case Motor::UpperActuator:
      m_upperActuator.setPower(power);
      break;
    case Motor::Turntable:
      m_turntableMotor.setPower(power);
      break;
  }
}

void OrionArm::stop() {
  setMotorPower(Motor::GrasperRotation, 0);
  setMotorPower(Motor::GrasperX, 0);
  setMotorPower(Motor::GrasperY, 0);
  setMotorPower(Motor::LowerActuator, 0);
  setMotorPower(Motor::Turntable, 0);
  setMotorPower(Motor::UpperActuator, 0);
}