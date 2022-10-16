#include <iostream>
#include "CPU.h"
#include "Instruction.h"

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

void Open6502::CPU::execute() {
  if (this->program_counter >= MAX_MEMORY_SIZE) {
    std::cerr << "MAX MEMORY ADDRESS REACHED: Program Finished" << std::endl;
    exit(0);
  }

  auto opcode = this->data_bus->read(this->program_counter);

  this->program_counter++;
  Instruction::Fecth(opcode, this, this->data_bus);
  std::cout << "CPU status: " << this->status << std::endl;
  std::cout << "CPU accumulator: " << unsigned(this->accumulator) << std::endl;
  this->program_counter++;

  this->execute();
}
