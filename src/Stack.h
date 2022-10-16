#pragma once

#include <cstdint>
#include <memory>
#include "DataBus.h"

namespace Open6502 {

class Stack {
public:
  Stack(const std::shared_ptr<DataBus>&);
  ~Stack();

  void reset();

  // Return 1 if fail
  uint8_t push(uint8_t value);
  void pop();
  uint8_t get() const;

private:
  static const uint16_t StartAddr = 0x0100;
  static const uint16_t EndAddr = 0x01FF;

  std::shared_ptr<DataBus> data_bus = nullptr;
  uint16_t index = StartAddr;
};

}
