#include <iostream>
#include "Instruction.h"

// TODO: in progress
void Open6502::Instruction::Fecth(uint8_t opcode, CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  switch (opcode) {
    /* ----------- LOGICAL AND ARITHMETIC OPCODES ---------- */
    case ORA_IMM::Opcode:
      ORA_IMM().execute(cpu, data_bus);
      break;
    case INX::Opcode:
      INX().execute(cpu, data_bus);
      break;
    case INY::Opcode:
      INY().execute(cpu, data_bus);
      break;

    /* ----------- MOVE OPCODES ---------- */
    case LDY_IMM::Opcode:
      LDY_IMM().execute(cpu, data_bus);
      break;
    case LDX_IMM::Opcode:
      LDX_IMM().execute(cpu, data_bus);
      break;
    case LDA_IMM::Opcode:
      LDA_IMM().execute(cpu, data_bus);
      break;

    /* ----------- JUMP OPCODES ---------- */
    case BRK::Opcode:
      BRK().execute(cpu, data_bus);
      break;
    default:
      std::cerr << "Error: Instruction not implemented: " << std::hex << unsigned(opcode) << std::dec << std::endl;
      exit(1);
      break;
  }
}

/* ----------- LOGICAL AND ARITHMETIC OPCODES ---------- */

void Open6502::ORA_IMM::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->program_counter++;
  cpu->accumulator = cpu->accumulator | data_bus->read(cpu->program_counter);
}

void Open6502::INX::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->x++;
}

void Open6502::INY::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->y++;
}

/* ----------- MOVE OPCODES ---------- */

void Open6502::LDY_IMM::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->program_counter++;
  cpu->y = data_bus->read(cpu->program_counter);
  cpu->status.zero = cpu->y == 0x00;
}

void Open6502::LDX_IMM::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->program_counter++;
  cpu->x = data_bus->read(cpu->program_counter);
  cpu->status.zero = cpu->x == 0x00;
}

void Open6502::LDA_IMM::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->program_counter++;
  cpu->accumulator = data_bus->read(cpu->program_counter);
  cpu->status.zero = cpu->accumulator == 0x00;
}

/* ----------- JUMP OPCODES ---------- */

void Open6502::BRK::execute(CPU* cpu, std::shared_ptr<DataBus> data_bus) {
  cpu->cycle += ClockCycles;
  cpu->stack.pop();
  cpu->status.b_flag = true;
  cpu->status.interrupt_disabled = true;
  cpu->program_counter = IRQ_VECTOR;
}
