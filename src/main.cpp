#include <iostream>
#include <chrono>
#include <thread>
#include <cassert>

#include <SDL2/SDL.h>

#include "gba/cartridge.hpp"
#include "gba/arm7tdmi.hpp"
#include "gba/ppu.hpp"
#include "gba/keypad.hpp"

static void printHeader(const Cartridge::Header &header) {
    std::cout << "GameTitle:" << header.gameTitle() << "\n"
              << "GameCode:" << header.gameCode() << "\n"
              << "MakerCode:" << header.makerCode() << "\n";
}

static std::chrono::nanoseconds getTimeFromMegaHertz(float megaHertz) {
    float hertz = megaHertz * 1000000;
    return std::chrono::nanoseconds((int64_t) (1000000000.0f / hertz));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please specify the path to a rom\n";
        return 0;
    }

    std::string romFilePath = argv[1];
    Cartridge cart = Cartridge::loadFromFile(romFilePath);
    printHeader(cart.getHeader());

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("gbaEmu", 0, 0, 240, 160, 0);
    SDL_Renderer *ren = SDL_CreateRenderer(window, 0, 0);
    SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(0, 240, 160, 24, SDL_PIXELFORMAT_RGB24);
    SDL_Texture *texture = nullptr;
    SDL_Rect rect = {0, 0, 240, 160};

    Bus bus(cart.getRom());
    Arm7TDMI cpu(bus);
    PPU ppu(bus);
    KeyPad keyPad(bus);

    cpu.reset(0x8000000);
    ppu.reset();

    std::chrono::nanoseconds cycleDuration = getTimeFromMegaHertz(16.78);

    std::chrono::high_resolution_clock::time_point frameStart;

    SDL_Event event;
    while (true) {
        frameStart = std::chrono::high_resolution_clock::now();

        //Parse events
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    keyPad.setKeyState(KeyPad::BUTTON_A, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_s:
                    keyPad.setKeyState(KeyPad::BUTTON_B, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_d:
                    keyPad.setKeyState(KeyPad::SELECT, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_f:
                    keyPad.setKeyState(KeyPad::START, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_RIGHT:
                    keyPad.setKeyState(KeyPad::RIGHT, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_LEFT:
                    keyPad.setKeyState(KeyPad::LEFT, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_UP:
                    keyPad.setKeyState(KeyPad::UP, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_DOWN:
                    keyPad.setKeyState(KeyPad::DOWN, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_g:
                    keyPad.setKeyState(KeyPad::BUTTON_R, event.type == SDL_KEYDOWN);
                    break;
                case SDLK_h:
                    keyPad.setKeyState(KeyPad::BUTTON_L, event.type == SDL_KEYDOWN);
                    break;
            }
        }

        //Execute one cycle
        cpu.step();
        ppu.step();

        //Draw the ppu output
        assert(surface->pitch == 240 * 3); //Ensure no padding
        surface->pixels = ppu.getOutput().getData();
        texture = SDL_CreateTextureFromSurface(ren, surface);

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, texture, &rect, &rect);
        SDL_RenderPresent(ren);

        //Check time
        auto frameTime = std::chrono::high_resolution_clock::now() - frameStart;
        if (cycleDuration < frameTime) {
            std::cout << "\rWarning: Simulation slow down, " +
                         std::to_string((frameTime - cycleDuration).count())
                         + " nanoseconds delay.";
            std::fflush(stdout);
        } else {
            std::cout << "\rSimulation speed ok, "
                         + std::to_string((cycleDuration - frameTime).count())
                         + " nanoseconds padding.";
            std::fflush(stdout);
            auto targetDifference = cycleDuration - frameTime;
            std::this_thread::sleep_for(targetDifference);
        }
    }

    if (texture != nullptr)
        SDL_DestroyTexture(texture);
    delete surface;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}