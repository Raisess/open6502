#include "CPU.h"

Open6502::CPU::CPU(const std::shared_ptr<DataBus>& data_bus)
  : data_bus(data_bus), stack(data_bus) {
  this->reset();
}

Open6502::CPU::~CPU() {}

void Open6502::CPU::reset() {
  this->status = Status::INTERRUPT_DISABLED;
  this->program_counter = 0x0000;
  this->stack_pointer = 0x00;
  this->accumulator = 0x00;
  this->x = 0x00;
  this->y = 0x00;
  this->data_bus->reset();
}

Open6502::CPU::Status Open6502::CPU::get_status() const {
  return this->status;
}

uint16_t Open6502::CPU::get_program_counter() const {
  return this->program_counter;
}

uint8_t Open6502::CPU::get_stack_pointer() const {
  return this->stack_pointer;
}
