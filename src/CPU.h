#pragma once

#include <cstdint>
#include <memory>
#include "DataBus.h"
#include "Stack.h"

namespace Open6502 {

class CPU {
  struct Status {
    bool carry = false;
    bool zero = false;
    bool interrupt_disabled = false;
    bool decimal = false;
    bool b_flag = false;
    bool overflow = false;
    bool negative = false;
  };

public:
  Stack stack;
  uint8_t cycle;
  // Registers
  struct Status status;
  uint16_t program_counter;
  uint8_t stack_pointer;
  uint8_t accumulator;
  uint8_t x;
  uint8_t y;

  CPU(const std::shared_ptr<DataBus>&);
  ~CPU();

  void reset();
  void execute();

private:
  std::shared_ptr<DataBus> data_bus = nullptr;

  void debug(uint8_t opcode);
};

}
