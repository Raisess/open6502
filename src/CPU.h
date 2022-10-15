#pragma once

#include <memory>
#include "DataBus.h"
#include "Stack.h"

namespace Open6502 {

class CPU {
public:
  enum Status {
    CARRY = 0b00000001,
    ZERO = 0b00000010,
    INTERRUPT_DISABLED = 0b00000100,
    DECIMAL = 0b00001000,
    B_FLAG = 0b00010000,
    OVERFLOW = 0b00100000,
    NEGATIVE = 0b01000000,
  };

  Status status;
  uint16_t program_counter;
  uint8_t stack_pointer;
  uint8_t accumulator;
  uint8_t x;
  uint8_t y;

  CPU(const std::shared_ptr<DataBus>&);
  ~CPU();

  void reset();

private:
  std::shared_ptr<DataBus> data_bus = nullptr;
  Stack stack;
};

}
