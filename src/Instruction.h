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

class BRK : public Instruction {
public:
  static const uint8_t Opcode = 0x00;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

class LDAI : public Instruction {
public:
  static const uint8_t Opcode = 0xA9;
  void execute(CPU*, std::shared_ptr<DataBus>) final override;
};

}
