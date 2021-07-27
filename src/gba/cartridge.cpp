#include "gba/cartridge.hpp"

#include <fstream>

Cartridge Cartridge::loadFromFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (file.fail()) {
        throw std::runtime_error("Failed to open cartridge at " + filepath);
    }
    return Cartridge(Memory(std::vector<char>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>())));
}

Cartridge::Cartridge() = default;

Cartridge::Cartridge(Memory rom)
        : rom(std::move(rom)) {
    header = {this->rom.getString(0x00, 192)};
}

const Cartridge::Header &Cartridge::getHeader() {
    return header;
}

const Memory &Cartridge::getRom() {
    return rom;
}
