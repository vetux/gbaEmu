#include "gba/arm7tdmi.hpp"

#include <utility>

Arm7TDMI::Arm7TDMI() = default;

Arm7TDMI::Arm7TDMI(Arm7TDMI::Registers registers)
        : registers(registers) {}
