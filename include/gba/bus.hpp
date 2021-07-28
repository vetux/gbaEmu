#ifndef GBAEMU_BUS_HPP
#define GBAEMU_BUS_HPP

#include <cstdint>

#include "gba/cartridge.hpp"

class Bus {
public:
    Bus();

    explicit Bus(Memory rom);

    std::vector<uint8_t> read(uint32_t address, size_t numberOfBytes);

    void write(uint32_t address, const std::vector<uint8_t> &bytes);

private:
    Memory wram;
    Memory iram;
    Memory io;
    Memory vram;
    Memory oam;
    Memory rom;
};

#endif //GBAEMU_BUS_HPP
