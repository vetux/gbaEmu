#include "gba/arm7tdmi.hpp"

#include <utility>

#include <cassert>

Arm7TDMI::Arm7TDMI() = default;

Arm7TDMI::Arm7TDMI(Bus bus)
        : bus(std::move(bus)),
          registers() {}

Arm7TDMI::Arm7TDMI(Bus bus, Arm7TDMI::Registers registers)
        : bus(std::move(bus)),
          registers(registers) {}

void Arm7TDMI::reset(uint32_t entryPoint) {
    //Reset registers
    registers = {};
    registers.r15 = entryPoint;
}

void Arm7TDMI::step() {
    //Check mode (ARM / THUMB)

    //Fetch instruction bytes from bus and call parser

    //Parser decodes and runs the instruction
}

const Arm7TDMI::Registers &Arm7TDMI::getRegisters() {
    return registers;
}

void Arm7TDMI::parseArm(const std::vector<uint8_t> &instruction) {
    assert(instruction.size() == 4);
}

void Arm7TDMI::parseThumb(const std::vector<uint8_t> &instruction) {
    assert(instruction.size() == 2);
}
