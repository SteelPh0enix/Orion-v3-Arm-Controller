#pragma once
#include <cstdint>
#include "../Module/module.hpp"

class BasicMotor : public Module {
 public:
  enum class Direction { Forward, Backward, None };

  BasicMotor() = default;
  BasicMotor(std::uint8_t PWMPin,
             std::uint8_t directionPinA,
             std::uint8_t directionPinB);
  void setPins(std::uint8_t PWMPin,
               std::uint8_t directionPin,
               std::uint8_t directionPinB);

  void setPower(int power);
  void setDirection(Direction forward);

 private:
  virtual bool internalInitialize() override;

  int m_power{0};

  std::uint8_t m_directionPinA{};
  std::uint8_t m_directionPinB{};
  std::uint8_t m_PWMPin{};
};