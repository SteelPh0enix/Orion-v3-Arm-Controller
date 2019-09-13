#pragma once
#include <cstdint>

namespace Pinout {
using PinT = std::uint8_t;
constexpr PinT LowerArmActuatorPWM{3};
constexpr PinT LowerArmActuatorDirectionA{28};
constexpr PinT LowerArmActuatorDirectionB{30};

constexpr PinT UpperArmActuatorPWM{4};
constexpr PinT UpperArmActuatorDirectionA{29};
constexpr PinT UpperArmActuatorDirectionB{31};

constexpr PinT GrasperRotationPWM{7};
constexpr PinT GrasperRotationDirection{27};
constexpr PinT GrasperRotationFeedback{};
constexpr PinT GrasperRotationDisable{23};
constexpr PinT GrasperRotationStatusFlag{};

constexpr PinT GrasperXPWM{6};
constexpr PinT GrasperXDirection{25};
constexpr PinT GrasperXFeedback{};
constexpr PinT GrasperXDisable{23};
constexpr PinT GrasperXStatusFlag{};

constexpr PinT GrasperYPWM{5};
constexpr PinT GrasperYDirection{26};
constexpr PinT GrasperYFeedback{};
constexpr PinT GrasperYDisable{22};
constexpr PinT GrasperYStatusFlag{};

constexpr PinT TurntablePWM{2};
constexpr PinT TurntableDirection{24};
constexpr PinT TurntableFeedback{};
constexpr PinT TurntableDisable{22};
constexpr PinT TurntableStatusFlag{};

}  // namespace Pinout