#ifndef GBAEMU_CARTRIDGE_HPP
#define GBAEMU_CARTRIDGE_HPP

#include <vector>
#include <string>

#include "gba/memory.hpp"

class Cartridge {
public:
    struct Header {
        std::string bytes; //Length : 192

        std::string entryPoint() const { return bytes.substr(0x0, 4); }

        std::string logo() const { return bytes.substr(0x004, 156); }

        std::string gameTitle() const { return bytes.substr(0x0A0, 12); }

        std::string gameCode() const { return bytes.substr(0x0AC, 4); }

        std::string makerCode() const { return bytes.substr(0x0B0, 2); }

        std::string fixedValue() const { return bytes.substr(0x0B2, 1); }

        std::string mainUnitCode() const { return bytes.substr(0x0B3, 1); }

        std::string deviceType() const { return bytes.substr(0x0B4, 1); }

        std::string reservedArea() const { return bytes.substr(0x0B5, 7); }

        std::string softwareVersion() const { return bytes.substr(0x0BC, 1); }

        std::string complementCheck() const { return bytes.substr(0x0BD, 1); }

        std::string reservedArea2() const { return bytes.substr(0x0BE, 2); }

        std::string ramEntryPoint() const { return bytes.substr(0x0C0, 4); }

        std::string bootMode() const { return bytes.substr(0x0C4, 1); }

        std::string slaveIDNumber() const { return bytes.substr(0x0C5, 1); }

        std::string notUsed() const { return bytes.substr(0x0C6, 26); }

        std::string joyBusEntryPoint() const { return bytes.substr(0x0E0, 4); }
    };

    static Cartridge loadFromFile(const std::string &filepath);

    Cartridge();

    explicit Cartridge(Memory rom);

    const Header &getHeader();

    const Memory &getRom();

private:
    Header header;
    Memory rom;
};

#endif //GBAEMU_CARTRIDGE_HPP
