#ifndef GBAEMU_MEMORY_HPP
#define GBAEMU_MEMORY_HPP

#include <vector>
#include <stdexcept>

class Memory {
public:
    std::vector<uint8_t> mem;

    Memory() = default;

    explicit Memory(std::vector<uint8_t> mem)
            : mem(std::move(mem)) {}

    explicit Memory(size_t size, uint8_t value = 0)
            : mem(size, value) {}

    Memory(const Memory &other) = default;

    Memory(Memory &&other) noexcept {
        mem = std::move(other.mem);
    }

    ~Memory() = default;

    Memory &operator=(const Memory &other) = default;

    std::vector<uint8_t> load(size_t address, size_t numberOfBytes) {
        std::vector<uint8_t> ret(numberOfBytes);
        for (size_t i = 0; i < numberOfBytes; i++) {
            ret[i] = mem.at(address + i);
        }
        return ret;
    }

    void store(size_t address, std::vector<uint8_t> bytes) {
        for (size_t i = 0; i < bytes.size(); i++) {
            mem.at(address + i) = bytes.at(i);
        }
    }

    std::string getString(size_t address, size_t size) {
        std::string ret;
        for (size_t i = address; i < address + size; i++) {
            ret += mem.at(i);
        }
        return ret;
    }

    size_t size() const {
        return mem.size();
    }
};

#endif //GBAEMU_MEMORY_HPP
