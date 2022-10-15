#pragma once

#include <array>
#include <cstdint>

#define MAX_MEMORY_SIZE 0xFFFF

namespace Open6502 {

class DataBus {
public:
  DataBus();
  ~DataBus();

  void reset();

  void write(uint16_t addr, uint8_t value);
  uint8_t read(uint16_t addr) const;

private:
  std::array<uint8_t, MAX_MEMORY_SIZE> memory;
};

}
