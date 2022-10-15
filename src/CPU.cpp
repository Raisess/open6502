#include "CPU.h"

Open6502::CPU::CPU(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus), stack(data_bus) {
  this->reset();
}

Open6502::CPU::~CPU() {}

void Open6502::CPU::reset() {
  this->data_bus->reset();
  this->stack.reset();
  this->status = Status::INTERRUPT_DISABLED;
  this->program_counter = 0x0000;
  this->stack_pointer = this->stack.get();
  this->accumulator = 0x00;
  this->x = 0x00;
  this->y = 0x00;
}
