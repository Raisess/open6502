#include <iostream>
#include "Stack.h"

Open6502::Stack::Stack(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus) {}

Open6502::Stack::~Stack() {}

void Open6502::Stack::reset() {
  this->index = Stack::StartAddr;
}

uint8_t Open6502::Stack::push(uint8_t value) {
  if (this->index == Stack::EndAddr) {
    return 1;
  }

  this->data_bus->write(this->index, value);
  this->index++;

  return 0;
}

void Open6502::Stack::pop() {
  this->data_bus->write(std::max(static_cast<int>(Stack::StartAddr), this->index - 1), 0x00);
  if (this->index > Stack::StartAddr) {
    this->index--;
  }
}

uint8_t Open6502::Stack::get() const {
  return this->data_bus->read(this->index - 1);
}
