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

// Interrupt Request
// BRK
class BRK : public Instruction {
public:
  static const uint8_t Opcode = 0x00;
  static const uint8_t ClockCycles = 1;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// Load Y Register (Immediate)
// LDY #$05
class LDYI : public Instruction {
public:
  static const uint8_t Opcode = 0xA0;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// Load X Register (Immediate)
// LDX #$05
class LDXI : public Instruction {
public:
  static const uint8_t Opcode = 0xA2;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

// Load Accumulator (Immediate)
// LDA #$05
class LDAI : public Instruction {
public:
  static const uint8_t Opcode = 0xA9;
  static const uint8_t ClockCycles = 2;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

}
