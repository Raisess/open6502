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

  CPU(const std::shared_ptr<DataBus>&);
  ~CPU();

  void reset();

  Status get_status() const;
  uint16_t get_program_counter() const;
  uint8_t get_stack_pointer() const;
  uint8_t get_accumulator() const;
  uint8_t get_x() const;
  uint8_t get_y() const;

private:
  std::shared_ptr<DataBus> data_bus = nullptr;
  Stack stack;

  Status status;
  uint16_t program_counter;
  uint8_t stack_pointer;
  uint8_t accumulator;
  uint8_t x;
  uint8_t y;
};

}
