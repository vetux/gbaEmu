#include "gba/keypad.hpp"

KeyPad::KeyPad(Bus &bus)
        : bus(bus) {}

void KeyPad::setKeyState(KeyPad::Key key, bool pressed) {
    throw std::runtime_error("Not Implemented");
}

bool KeyPad::getKeyState(KeyPad::Key key) {
    throw std::runtime_error("Not Implemented");
}

void KeyPad::setKeyStates(const std::map<Key, bool> &keys) {
    for (auto &p : keys) {
        setKeyState(p.first, p.second);
    }
}

std::map<KeyPad::Key, bool> KeyPad::getKeyStates() {
    std::map<Key, bool> ret;
    ret[BUTTON_A] = getKeyState(BUTTON_A);
    ret[BUTTON_B] = getKeyState(BUTTON_B);
    ret[SELECT] = getKeyState(SELECT);
    ret[START] = getKeyState(START);
    ret[RIGHT] = getKeyState(RIGHT);
    ret[LEFT] = getKeyState(LEFT);
    ret[UP] = getKeyState(UP);
    ret[DOWN] = getKeyState(DOWN);
    ret[BUTTON_R] = getKeyState(BUTTON_R);
    ret[BUTTON_L] = getKeyState(BUTTON_L);
    return ret;
}
