// Copyright 2020 A.SHT
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
  std::cout << infix2postfix("23 + 35 / 244 + (56 + 9 * 4)") << std::endl;
  std::cout << infix2postfix("(6 * (4 - 2) + 5) * (2.6 + 3 * 7)") << std::endl;
  return 0;
}
