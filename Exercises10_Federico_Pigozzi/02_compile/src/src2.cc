#include <iostream>
#include "utility.h"
#include <string>

static std::string greetings() {
  std::string s{"Good afternoon\n"};
  return s;
}

void print_lower(const std::string& s) {
   auto res1 = to_lower(greetings());
   auto res2 = to_lower(s);
   std::cout << res1;
   std::cout << res2;
//   std::cout << greetings();
//   std::cout << s;
   std::cout << std::endl;
}
