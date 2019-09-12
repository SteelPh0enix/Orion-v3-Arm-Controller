#pragma once
#include <cstdint>
#include "../Module/module.hpp"

class BasicMotor : public Module {
 public:
  BasicMotor(std::uint8_t PWMPin, std::uint8_t directionPin);

 private:
};