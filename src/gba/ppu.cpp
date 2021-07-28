#include "gba/ppu.hpp"

PPU::PPU(Bus &bus)
        : bus(bus),
          output(240, 160) {}

void PPU::reset() {}

void PPU::step() {
    //Read values from bus and construct the output image

    //Set some pixels for testing
    for (int x = 0; x < 240; x++) {
        for (int y = 0; y < 160; y++) {
            output.setPixel(x, y, ColorRGB(0, 125, 125));
        }
    }
    for (int x = 240 / 4; x < 240 - 240 / 4; x++) {
        for (int y = 160 / 4; y < 160 - 160 / 4; y++) {
            output.setPixel(x, y, ColorRGB(125, 0, 0));
        }
    }
}

ImageBuffer<ColorRGB> &PPU::getOutput() {
    return output;
}
