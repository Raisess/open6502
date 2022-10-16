#include <cstdlib>
#include <iostream>
#include <memory>
#include "CPU.h"
#include "DataBus.h"

using namespace Open6502;

int main(int argc, char* argv[]) {
  auto memory = std::make_shared<DataBus>();
  CPU cpu(memory);

  for (int i = 1; i < argc; i++) {
    // std::cout << i - 1 << " " << argv[i] << std::endl;
    memory->write(
      static_cast<uint16_t>(i - 1),
      static_cast<uint8_t>(std::stol(argv[i], nullptr, 16))
    );
  }

  cpu.execute();
  return 0;
}
