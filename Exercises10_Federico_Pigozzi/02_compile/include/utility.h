#ifndef __UTILITY__
#define __UTILITY__


#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

inline std::string to_upper(const std::string& os) {
  static int n = 0;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}

inline std::string to_lower(const std::string& os) {
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), tolower);
  return s;
}


#endif
