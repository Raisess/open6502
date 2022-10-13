#include "DataBus.h"

Open6502::DataBus::DataBus() {
  for (uint16_t i = 0; i < MAX_MEMORY_SIZE; i++) {
    this->memory[i] = 0xFF;
  }
}

Open6502::DataBus::~DataBus() {}

void Open6502::DataBus::write(uint16_t addr, uint8_t value) {
  this->memory[addr] = value;
}

uint8_t Open6502::DataBus::read(uint16_t addr) const {
  return this->memory[addr];
}
