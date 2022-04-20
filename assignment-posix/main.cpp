#include <cstring>
#include <iostream>

#include "producer_consumer.h"

void usage(std::ostream &out, const char *executor) {
  out << "Usage: " << executor << " <n> <limit> [-debug]" << std::endl;
}

int main(int argc, char *argv[]) {
  int n = 1, limit = 1000;
  bool debug_enabled = false;

  if (argc > 2) {
    // mandatory program arguments
    n = std::stoi(argv[1]);
    limit = std::abs(std::stoi(argv[2]));
    // optional option, run in debug mode
    debug_enabled = (argc > 3) && !std::strcmp(argv[3], "-debug");
  } else {
    usage(std::cerr, argv[0]);
  }

  std::cout << run_threads(n, limit, debug_enabled) << std::endl;
  return 0;
}
