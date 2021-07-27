#ifndef GBAEMU_ARM7TDI_HPP
#define GBAEMU_ARM7TDI_HPP

#include <cstdint>

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

    Arm7TDMI();

    explicit Arm7TDMI(Registers registers);

private:
    Registers registers{};
};

#endif //GBAEMU_ARM7TDI_HPP
