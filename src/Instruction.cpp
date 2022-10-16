#include <iostream>
#include "Instruction.h"

// TODO: in progress
void Open6502::Instruction::Fecth(uint8_t opcode, CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  switch (opcode) {
    case BRK::Opcode:
      BRK().execute(cpu, data_bus);
      break;
    case LDYI::Opcode:
      LDYI().execute(cpu, data_bus);
      break;
    case LDXI::Opcode:
      LDXI().execute(cpu, data_bus);
      break;
    case LDAI::Opcode:
      LDAI().execute(cpu, data_bus);
      break;
    default:
      std::cerr << "Error: Instruction not implemented: " << std::hex << unsigned(opcode) << std::dec << std::endl;
      exit(1);
      break;
  }
}

// TODO: in progress
void Open6502::BRK::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->program_counter = 0xFFFE;
}

void Open6502::LDYI::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  for (uint8_t i = 0; i < LDYI::ClockCycles; i++) {
    switch (i) {
      case 0:
        cpu->program_counter++;
      case 1:
        auto addr = data_bus->read(cpu->program_counter);
        cpu->y = addr;
        if (cpu->y == 0x00) cpu->status = CPU::Status::ZERO;
    }
  }
}

void Open6502::LDXI::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  for (uint8_t i = 0; i < LDXI::ClockCycles; i++) {
    switch (i) {
      case 0:
        cpu->program_counter++;
      case 1:
        auto addr = data_bus->read(cpu->program_counter);
        cpu->x = addr;
        if (cpu->x == 0x00) cpu->status = CPU::Status::ZERO;
    }
  }
}

void Open6502::LDAI::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  for (uint8_t i = 0; i < LDAI::ClockCycles; i++) {
    switch (i) {
      case 0:
        cpu->program_counter++;
      case 1:
        auto addr = data_bus->read(cpu->program_counter);
        cpu->accumulator = addr;
        if (cpu->accumulator == 0x00) cpu->status = CPU::Status::ZERO;
    }
  }
}
