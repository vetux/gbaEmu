#ifndef GBAEMU_ARM7TDI_HPP
#define GBAEMU_ARM7TDI_HPP

#include <cstdint>

#include "gba/bus.hpp"

class Arm7TDMI {
public:
    struct Registers {
        uint32_t r0;
        uint32_t r1;
        uint32_t r2;
        uint32_t r3;
        uint32_t r4;
        uint32_t r5;
        uint32_t r6;
        uint32_t r7;
        uint32_t r8;
        uint32_t r9;
        uint32_t r10;
        uint32_t r11;
        uint32_t r12;
        uint32_t r13;
        uint32_t r14;
        uint32_t r15; //PC
        uint32_t CPSR;
        uint32_t SPSR;
    };

    explicit Arm7TDMI(Bus &bus);

    Arm7TDMI(Bus &bus, Registers registers);

    const Registers &getRegisters();

    void reset(uint32_t entryPoint);

    void step();

private:
    Bus &bus;
    Registers registers{};

    void parseArm(const std::vector<uint8_t> &instruction);

    void parseThumb(const std::vector<uint8_t> &instruction);
};

#endif //GBAEMU_ARM7TDI_HPP
