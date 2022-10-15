#include <iostream>
#include <memory>
#include "CPU.h"
#include "DataBus.h"

using namespace Open6502;

int main(int argc, char* argv[]) {
  auto data_bus = std::make_shared<DataBus>();
  CPU cpu(data_bus);

  data_bus->write(0xEEEE, 0xEF);

  std::cout << unsigned(data_bus->read(0x0000)) << std::endl;
  std::cout << unsigned(data_bus->read(0xEEEE)) << std::endl;
  std::cout << unsigned(data_bus->read(0xFFFE)) << std::endl;

  return 0;
}
