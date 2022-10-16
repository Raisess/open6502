#pragma once

#include <cstdint>
#include <memory>
#include "CPU.h"
#include "DataBus.h"

namespace Open6502 {

class Instruction {
public:
  static void Fecth(uint8_t opcode, CPU*, std::shared_ptr<DataBus>);
  virtual void execute(CPU*, std::shared_ptr<DataBus>) = 0;
};

/* ----------- LOGICAL AND ARITHMETIC OPCODES ---------- */

// Or A (Immediate)
// ORA
class ORA_IMM : public Instruction {
public:
  static const uint8_t Opcode = 0x09;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// INX (Implied)
class INX : public Instruction {
public:
  static const uint8_t Opcode = 0xE8;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// INY (Implied)
class INY : public Instruction {
public:
  static const uint8_t Opcode = 0xC8;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

/* ----------- MOVE OPCODES ---------- */

// Load Y Register (Immediate)
// LDY #$05
class LDY_IMM : public Instruction {
public:
  static const uint8_t Opcode = 0xA0;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// Load X Register (Immediate)
// LDX #$05
class LDX_IMM : public Instruction {
public:
  static const uint8_t Opcode = 0xA2;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// Load Accumulator (Immediate)
// LDA #$05
class LDA_IMM : public Instruction {
public:
  static const uint8_t Opcode = 0xA9;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

/* ----------- JUMP OPCODES ---------- */

// Interrupt Request
// BRK
class BRK : public Instruction {
public:
  static const uint8_t Opcode = 0x00;
  static const uint8_t ClockCycles = 1;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

}
