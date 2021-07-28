#ifndef GBAEMU_PPU_HPP
#define GBAEMU_PPU_HPP

#include "gba/bus.hpp"

#include "util/imagebuffer.hpp"
#include "util/color.hpp"

/**
 * The ppu updates an imagebuffer on the cpu based on values in the bus memory (vram, oam),
 * to my current understanding it also can modify values in the bus memory and issue interrupts,
 * therefore for now the PPU has a reset and step method simulating the PPU clock altough i hope i can get
 * away with not simulating the whole ppu behaviour and just construct the image each frame.
 */
class PPU {
public:
    explicit PPU(Bus &bus);

    void reset();

    void step();

    /**
     * @return The "framebuffer" which should be currently displayed on the screen.
     */
    ImageBuffer<ColorRGB> &getOutput();

private:
    Bus &bus;
    ImageBuffer<ColorRGB> output;
};

#endif //GBAEMU_PPU_HPP
