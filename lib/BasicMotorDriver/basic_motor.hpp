#pragma once
#include <stdint.h>
#include "../Module/module.hpp"

class BasicMotor : public Module {
 public:
  enum class Direction { Forward, Backward, None };

  BasicMotor() = default;
  BasicMotor(uint8_t PWMPin, uint8_t directionPinA, uint8_t directionPinB);
  void setPins(uint8_t PWMPin, uint8_t directionPin, uint8_t directionPinB);

  void setPower(int power);
  void setDirection(Direction forward);

 private:
  virtual bool internalInitialize() override;

  int m_power{0};

  uint8_t m_directionPinA{};
  uint8_t m_directionPinB{};
  uint8_t m_PWMPin{};
};