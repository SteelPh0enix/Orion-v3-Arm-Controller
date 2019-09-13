#include "basic_motor.hpp"
#include <Arduino.h>

BasicMotor::BasicMotor(std::uint8_t PWMPin, std::uint8_t directionPinA, std::uint8_t directionPinB) {
  setPins(PWMPin, directionPinA, directionPinB);
}

void BasicMotor::setPins(std::uint8_t PWMPin, std::uint8_t directionPinA, std::uint8_t directionPinB) {
  m_directionPinA = directionPinA;
  m_directionPinB = directionPinB;
  m_PWMPin = PWMPin;
  pinsHasBeenSet();
}

void BasicMotor::setPower(int power) {
  power = constrain(power, -PWMResolution(), PWMResolution());
  m_power = power;
  analogWrite(m_PWMPin, abs(power));

  if (m_power < 0) {
    setDirection(Direction::Backward);
  } else if (m_power == 0) {
    setDirection(Direction::None);
  } else {
    setDirection(Direction::Forward);
  }
}

void BasicMotor::setDirection(BasicMotor::Direction direction) {
  switch (direction) {
    case Direction::Forward: {
      digitalWrite(m_directionPinA, HIGH);
      digitalWrite(m_directionPinB, LOW);
      break;
    }
    case Direction::Backward: {
      digitalWrite(m_directionPinA, LOW);
      digitalWrite(m_directionPinB, HIGH);
      break;
    }
    case Direction::None: {
      digitalWrite(m_directionPinB, LOW);
      digitalWrite(m_directionPinB, LOW);
      break;
    }
  }
}

bool BasicMotor::internalInitialize() {
    pinMode(m_PWMPin, OUTPUT);
    pinMode(m_directionPinB, OUTPUT);
    pinMode(m_directionPinB, OUTPUT);
    return true;
}