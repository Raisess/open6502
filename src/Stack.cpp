#include <iostream>
#include "Stack.h"

uint16_t Open6502::Stack::StartAddr = 0x0100;
uint16_t Open6502::Stack::EndAddr = 0x01FF;

Open6502::Stack::Stack(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus) {}

Open6502::Stack::~Stack() {}

void Open6502::Stack::reset() {
  this->index = Stack::StartAddr;
}

uint8_t Open6502::Stack::push(uint8_t value) {
  if (this->index == Stack::EndAddr) {
    std::cerr << "Stack Overflow" << std::endl;
    return 1;
  }

  this->data_bus->write(this->index, value);
  this->index++;

  return 0;
}

void Open6502::Stack::pop() {
  this->data_bus->write(std::max(static_cast<int>(Stack::StartAddr), this->index - 1), 0x00);
  this->index--;
}

uint8_t Open6502::Stack::get() const {
  return this->data_bus->read(this->index - 1);
}
