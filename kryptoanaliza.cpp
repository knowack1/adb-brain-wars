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
#include <cstdint>
#include <cmath>

template <class Container>
std::ostream& printResult(const Container& cont, int N) {
  if (cont.empty()) {
    std::cout << "not exist" << std::endl;
  }
  for (auto& i : cont)
    std::cout << i << " " << N - i << std::endl;
  return std::cout;
}

template <class Container>
std::ostream& print(const Container& cont, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << cont[i] << ' ';
  }
  return std::cout;
}

std::ostream& print(const std::vector<std::pair<int, int> >& cont) {
  if (cont.empty()) {
    std::cout << "not exist" << std::endl;
  }
  for (auto& i : cont)
    std::cout << i.first << " " << i.second << std::endl;
  return std::cout;
}

int power[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

template <class Array>
int toNumber(const Array& array, size_t size) {
  int number = 0;
  for (size_t i = 0; i < size; ++i) {
    number += array[i] * power[size - i - 1];
  }
  return number;
}

template <class Array>
void toArray(Array& array, size_t size, int number) {
  int i = size;
  while (number) {
    array[--i] = number % 10;
    number /= 10;
  }
  while (i) {
    array[--i] = 0;
  }
}

int A[10] = {0};
int B[10] = {0};

int main(int argc, char* argv[]) {
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);
  while (T) {
    std::vector<int> result;
    char buff[11] = {0};
    scanf("%s", buff);
    line = buff;
    const int N = std::strtoull(line.c_str(), NULL, 10);
    const size_t size = line.size();
    int i = 0;
    for (auto c : line) {
      A[i] = c - '0';
      B[i] = c - '0';
      i++;
    }
    std::sort(std::begin(A), std::begin(A) + size);

    do {

      int a = toNumber(A, size);
      int b = N - a;
      if (a > b) {
        break;
      }
      toArray(B, size, b);
      if (std::is_permutation(std::begin(A), std::begin(A) + size, std::begin(B),
                              std::begin(B) + size)) {
        result.push_back(a);
      }
    } while (std::next_permutation(std::begin(A), std::begin(A) + size));

    printResult(result, N);
    T--;
  }
}
