#include <iostream>
#include "utility.h"
#include <string>

static std::string greetings() {
  std::string s{"Welcome\n"};
  return s;
}

void print_upper(const std::string& s) {
  auto res1 = to_upper(greetings());
  auto res2 = to_upper(s);
  std::cout << res1;
  std::cout << res2;
  std::cout << std::endl;
}
