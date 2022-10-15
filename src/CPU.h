#pragma once

#include <memory>
#include "DataBus.h"

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

  uint8_t accumulator = 0x00;
  uint8_t x = 0x00;
  uint8_t y = 0x00;

  CPU(const std::shared_ptr<DataBus>& data_bus);
  ~CPU();

  void reset();

  Status get_status() const;
  uint16_t get_program_counter() const;
  uint8_t get_stack_pointer() const;

private:
  std::shared_ptr<DataBus> data_bus = nullptr;
  Status status = Status::ZERO;
  uint16_t program_counter = 0x0000;
  uint8_t stack_pointer = 0x00;
};

}
