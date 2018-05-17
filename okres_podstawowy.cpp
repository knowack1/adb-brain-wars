#include <iostream>
#include <string>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cstring>

size_t next(std::size_t pos, size_t step, size_t size) {
  return (pos + step) % size;
}

bool equal(size_t pos, size_t step, const std::string& range) {
  return std::strncmp(range.c_str() + pos, range.c_str() + pos + step, step) == 0;
}

template <class Container>
std::ostream& print(const Container& cont) {
  for (auto i : cont)
    std::cout << i << ' ';
  return std::cout;
}

bool test(size_t step, const std::string& input) {
  bool ret = true;
  for (size_t pos = 0; pos + pos < input.size(); pos += step) {
    if (std::strncmp(input.c_str() + pos, input.c_str() + pos + step, step) != 0) {
      ret = false;
      break;
    }
  }
  return ret;
}

size_t test(const std::string& input) {
  size_t step = 2;
  bool found = false;
  for (; step <= input.size() / 2; ++step) {
    if (input.size() % step == 0) {
      if (test(step, input)) {
        found = true;
        break;
      }
    }
  }
  return found ? step : input.size();
}

int main(int argc, char* argv[]) {
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  while (T) {
    std::getline(std::cin, line);
    std::cout << test(line) << std::endl;
    T--;
  }
  return 0;
}
