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
  this->cycle = 0;
  this->status.interrupt_disabled = true;
  this->program_counter = RESET_VECTOR;
  this->stack_pointer = this->stack.get();
  this->accumulator = 0x00;
  this->x = 0x00;
  this->y = 0x00;
}

void Open6502::CPU::execute() {
  if (this->status.b_flag) {
    std::cerr << "PROGRAM FINISHED: Break Interrupt" << std::endl;
    exit(1);
  }

  if (this->status.overflow) {
    std::cerr << "PROGRAM FINISHED: Stack Overflow" << std::endl;
    exit(1);
  }

  if (this->program_counter >= MAX_MEMORY_SIZE) {
    std::cerr << "PROGRAM FINISHED: Program counter out of bounds" << std::endl;
    exit(1);
  }

  const auto opcode = this->data_bus->read(this->program_counter);
  Instruction::Fecth(opcode, this, this->data_bus);
  this->debug(opcode);
  this->program_counter++;
  this->execute();
}

void Open6502::CPU::debug(uint8_t opcode) {
  if (DEBUG) {
    std::cout << std::hex << "---> Opcode: " << unsigned(opcode) << std::endl;
    std::cout << "CPU->cycle: " << unsigned(this->cycle) << std::endl;
    std::cout << "CPU->program_counter: " << unsigned(this->program_counter) << std::endl;
    std::cout << "CPU->stack_pointer: " << unsigned(this->stack_pointer) << std::endl;
    std::cout << "CPU->accumulator: " << unsigned(this->accumulator) << std::endl;
    std::cout << "CPU->x: " << unsigned(this->x) << std::endl;
    std::cout << "CPU->y: " << unsigned(this->y) << std::endl << std::dec;
  }
}
