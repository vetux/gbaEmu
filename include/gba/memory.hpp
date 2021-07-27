#ifndef GBAEMU_MEMORY_HPP
#define GBAEMU_MEMORY_HPP

#include <vector>

class Memory {
public:
    std::vector<char> mem;

    Memory() = default;

    explicit Memory(std::vector<char> mem)
            : mem(std::move(mem)) {}

    explicit Memory(size_t size, char value = 0)
            : mem(size, value) {}

    Memory(Memory &&other) noexcept {
        mem = std::move(other.mem);
    }

    ~Memory() = default;

    std::string getString(size_t address, size_t size) {
        std::string ret;
        for (size_t i = address; i < address + size; i++) {
            ret += mem.at(i);
        }
        return ret;
    }
};

#endif //GBAEMU_MEMORY_HPP
