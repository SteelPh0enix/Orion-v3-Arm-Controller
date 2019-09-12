#pragma once
#include <cstdint>

namespace Pinout {
using PinT = std::uint8_t;
constexpr PinT LowerArmActuatorPWM{};
constexpr PinT UpperArmActuatorPWM{};

constexpr PinT GrasperRotationPWM{};
constexpr PinT GrasperRotationDirection{};
constexpr PinT GrasperRotationFeedback{};
constexpr PinT GrasperRotationDisable{};
constexpr PinT GrasperRotationStatusFlag{};

constexpr PinT GrasperXPWM{};
constexpr PinT GrasperXDirection{};
constexpr PinT GrasperXFeedback{};
constexpr PinT GrasperXDisable{};
constexpr PinT GrasperXStatusFlag{};

constexpr PinT GrasperYPWM{};
constexpr PinT GrasperYDirection{};
constexpr PinT GrasperYFeedback{};
constexpr PinT GrasperYDisable{};
constexpr PinT GrasperYStatusFlag{};

constexpr PinT TurntablePWM{};
constexpr PinT TurntableDirection{};
constexpr PinT TurntableFeedback{};
constexpr PinT TurntableDisable{};
constexpr PinT TurntableStatusFlag{};

}  // namespace Pinout