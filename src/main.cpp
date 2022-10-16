#include <iostream>
#include <memory>
#include "CPU.h"
#include "DataBus.h"
//#include "Stack.h"

using namespace Open6502;

int main(int argc, char* argv[]) {
  auto data_bus = std::make_shared<DataBus>();
  CPU cpu(data_bus);

  // Test DataBus
  /*std::cout << "Test DataBus" << std::endl;

  data_bus->write(0xEEEE, 0xEF);
  std::cout << unsigned(data_bus->read(0x0000)) << std::endl;
  std::cout << unsigned(data_bus->read(0xEEEE)) << std::endl;
  std::cout << unsigned(data_bus->read(0xFFFE)) << std::endl;

  // Test Stack
  std::cout << "Test Stack" << std::endl;
  Stack stack(data_bus);

  stack.push(0xFF);
  std::cout << unsigned(stack.get()) << std::endl;
  stack.pop();
  std::cout << unsigned(stack.get()) << std::endl;*/

  // Test CPU
  std::cout << "Test CPU" << std::endl;
  // LDA #10
  data_bus->write(0x0000, 0xA9);
  data_bus->write(0x0001, 0x0A);
  // LDA #5
  data_bus->write(0x0002, 0xA9);
  data_bus->write(0x0003, 0x05);
  // BRK
  data_bus->write(0x0004, 0x00);
  cpu.execute();

  return 0;
}
