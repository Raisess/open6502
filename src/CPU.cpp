#include "CPU.h"

Open6502::CPU::CPU(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus) {
  this->reset();
}

Open6502::CPU::~CPU() {}

void Open6502::CPU::reset() {
  this->status = Status::ZERO;
}

Open6502::CPU::Status Open6502::CPU::get_status() const {
  return this->status;
}
