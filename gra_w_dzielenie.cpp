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

template <class Container>
std::ostream& print(const Container& cont) {
  for (auto i : cont)
    std::cout << i << ' ';
  return std::cout;
}

std::vector<int> split(const std::string& str) {
  std::vector<int> ret;
  std::istringstream iss(str);
  for (auto it = std::istream_iterator<std::string>(iss);
       it != std::istream_iterator<std::string>(); ++it) {
    ret.push_back(stoi(*it));
  }
  return ret;
}

int cal(const std::vector<int>& abc) {
  int sum = std::accumulate(abc.begin(), abc.end(), 1, std::multiplies<int>());
  for (size_t i = 0; i < abc.size(); ++i) {
    for (size_t j = 0; j < abc.size(); ++j) {
      if (i != j && abc[i] > 1 && abc[j] % abc[i] == 0) {
        std::vector<int> tmp = abc;
        tmp[j] = abc[j] / abc[i];
        int tmp_sum = cal(tmp);
        if (tmp_sum < sum) {
          sum = tmp_sum;
        }
      }
    }
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  while (T) {
    std::getline(std::cin, line);
    auto abc = split(line);
    std::cout << cal(abc) << std::endl;
    T--;
  }
  return 0;
}
