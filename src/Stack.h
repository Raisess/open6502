#pragma once

#include <cstdint>
#include <memory>
#include "DataBus.h"

namespace Open6502 {

class Stack {
public:
  Stack(const std::shared_ptr<DataBus>&);
  ~Stack();

  // Return 1 if fail
  uint8_t push(uint8_t value);
  void pop();
  uint8_t get(uint16_t addr) const;

private:
  static uint16_t StartAddr;
  static uint16_t EndAddr;
  uint16_t index = Stack::StartAddr;
  std::shared_ptr<DataBus> data_bus = nullptr;
};

}
