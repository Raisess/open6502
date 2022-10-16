#include <iostream>
#include "Instruction.h"

// TODO: in progress
void Open6502::Instruction::Fecth(uint8_t opcode, CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  switch (opcode) {
    case BRK::Opcode:
      BRK().execute(cpu, data_bus);
      break;
    case LDAI::Opcode:
      LDAI().execute(cpu, data_bus);
      break;
  }
}

// TODO: in progress
void Open6502::BRK::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  std::cout << "BRK" << std::endl;
  exit(0);
}

// TODO: in progress
void Open6502::LDAI::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  std::cout << "LDA Immediate" << std::endl;
  auto argument = data_bus->read(cpu->program_counter);
  cpu->accumulator = argument;
}
