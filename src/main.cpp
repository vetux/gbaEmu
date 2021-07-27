#include <iostream>

#include "gba/cartridge.hpp"
#include "gba/arm7tdmi.hpp"

static void printHeader(const Cartridge::Header &header) {
    std::cout << "GameTitle:" << header.gameTitle() << "\n"
              << "GameCode:" << header.gameCode() << "\n"
              << "MakerCode:" << header.makerCode() << "\n";
}

int main(int argc, char *argv[]) {
    static_assert(sizeof(char) == 1, "Unsupported platform (char is not 1 byte");

    if (argc < 2) {
        std::cout << "Please specify the path to a rom\n";
        return 0;
    }

    std::string romFilePath = argv[1];

    Cartridge cart = Cartridge::loadFromFile(romFilePath);

    printHeader(cart.getHeader());

    return 0;
}