#include <stdint.h>
#include <stdlib.h>

namespace Config {
constexpr size_t JsonBufferSize{256};

namespace Json {
constexpr char const* const ErrorCodeKey{"ErrorCode"};
constexpr char const* const ErrorDescriptionKey{"ErrorDescription"};

constexpr char const* const LowerActuatorPowerKey{"LAC"};
constexpr char const* const UpperActuatorPowerKey{"UAC"};
constexpr char const* const TurntablePowerKey{"TRT"};
constexpr char const* const GrasperRotationPowerKey{"GRPR"};
constexpr char const* const GrasperXAxisPowerKey{"GRPX"};
constexpr char const* const GrasperYAxisPowerKey{"GRPY"};
}  // namespace Json
}  // namespace Config