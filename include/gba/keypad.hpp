#ifndef GBAEMU_KEYPAD_HPP
#define GBAEMU_KEYPAD_HPP

#include <map>

#include "gba/bus.hpp"

/**
 * The keypad is a small abstraction around the mapped io memory which allows setting the individual button states
 */
class KeyPad {
public:
    enum Key {
        BUTTON_A,
        BUTTON_B,
        SELECT,
        START,
        RIGHT,
        LEFT,
        UP,
        DOWN,
        BUTTON_R,
        BUTTON_L
    };

    explicit KeyPad(Bus &bus);

    void setKeyState(Key key, bool pressed);

    bool getKeyState(Key key);

    void setKeyStates(const std::map<Key, bool> &keys);

    std::map<Key, bool> getKeyStates();

private:
    Bus &bus;
};

#endif //GBAEMU_KEYPAD_HPP
