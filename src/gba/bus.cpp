#include "gba/bus.hpp"

#include <stdexcept>

// https://github.com/Ensiss/pokebot/wiki/GBA-Memory-Map

#define ADDR_WRAM 0x2000000
#define ADDR_IRAM 0x3000000
#define ADDR_IO 0x4000000
#define ADDR_VRAM 0x6000000
#define ADDR_OAM 0x7000000
#define ADDR_ROM 0x8000000

#define SIZE_WRAM 0x40000
#define SIZE_IRAM 0x08000
#define SIZE_IO 0x003FF
#define SIZE_VRAM 0x18000
#define SIZE_OAM 0x00400
#define SIZE_ROM 0x1000000

Bus::Bus()
        : wram(SIZE_WRAM),
          iram(SIZE_IRAM),
          vram(SIZE_VRAM),
          rom(0) {}

Bus::Bus(Memory rom)
        : wram(SIZE_WRAM),
          iram(SIZE_IRAM),
          vram(SIZE_VRAM),
          rom(std::move(rom)) {}

std::vector<uint8_t> Bus::read(uint32_t address, size_t numberOfBytes) {
    if (address < ADDR_WRAM) {
        throw std::runtime_error("Invalid address " + std::to_string(address));
    }
    if (address < ADDR_IRAM) {
        return wram.load(address - ADDR_WRAM, numberOfBytes);
    } else if (address < ADDR_IO) {
        return iram.load(address - ADDR_IRAM, numberOfBytes);
    } else if (address < ADDR_VRAM) {
        return io.load(address - ADDR_IO, numberOfBytes);
    } else if (address < ADDR_OAM) {
        return vram.load(address - ADDR_VRAM, numberOfBytes);
    } else if (address < ADDR_ROM) {
        return oam.load(address - ADDR_OAM, numberOfBytes);
    } else if (address < ADDR_ROM + rom.size()) {
        return rom.load(address - ADDR_ROM, numberOfBytes);
    } else {
        throw std::runtime_error("Invalid address " + std::to_string(address));
    }
}

void Bus::write(uint32_t address, const std::vector<uint8_t> &bytes) {
    if (address < ADDR_WRAM) {
        throw std::runtime_error("Invalid address " + std::to_string(address));
    }
    if (address < ADDR_IRAM) {
        return wram.store(address - ADDR_WRAM, bytes);
    } else if (address < ADDR_IO) {
        return iram.store(address - ADDR_IRAM, bytes);
    } else if (address < ADDR_VRAM) {
        return io.store(address - ADDR_IO, bytes);
    } else if (address < ADDR_OAM) {
        return vram.store(address - ADDR_VRAM, bytes);
    } else if (address < ADDR_ROM) {
        return oam.store(address - ADDR_OAM, bytes);
    } else if (address < ADDR_ROM + rom.size()) {
        return rom.store(address - ADDR_ROM, bytes);
    } else {
        throw std::runtime_error("Invalid address " + std::to_string(address));
    }
}