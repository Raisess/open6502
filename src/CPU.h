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

  CPU(const std::shared_ptr<DataBus>& data_bus);
  ~CPU();

  void reset();
  Status get_status() const;

private:
  std::shared_ptr<DataBus> data_bus = nullptr;
  Status status;
};

}
