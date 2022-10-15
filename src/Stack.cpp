#include <iostream>
#include "Stack.h"

uint16_t Open6502::Stack::StartAddr = 0x0100;
uint16_t Open6502::Stack::EndAddr = 0x01FF;

Open6502::Stack::Stack(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus) {}

Open6502::Stack::~Stack() {}

uint8_t Open6502::Stack::push(uint8_t value) {
  if (index == Stack::EndAddr) {
    std::cerr << "Stack Overflow" << std::endl;
    return 1;
  }

  this->data_bus->write(index, value);
  index++;

  return 0;
}

void Open6502::Stack::pop() {
  this->data_bus->write(std::max(static_cast<int>(Stack::StartAddr), index - 1), 0x00);
}

uint8_t Open6502::Stack::get(uint16_t addr) const {
  return this->data_bus->read(std::min(Stack::EndAddr, addr));
}
