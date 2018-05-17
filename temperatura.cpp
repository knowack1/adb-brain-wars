#include <iostream>
#include <string>
#include <limits>
#include <cstdio>

bool test(int n, int N, const std::string& seq) {
  bool ret = true;
  int temp = n;

  for (std::string::const_iterator it = seq.begin(); it != seq.end(); it++) {
    if (*it == 'U') {
      temp++;
    }
    else if (*it == 'D') {
      temp--;
    }
    if (temp < 1 || temp > N) {
      ret = false;
      break;
    }
  }
  return ret;
}

int main(int argc, char* argv[]) {
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  while (T) {
    char c;
    int temp = 1;
    std::string result = "NO";
    std::getline(std::cin, line);
    const int N = std::stoi(line);
    int n = 1;
    std::getline(std::cin, line);
    while (n <= N) {
      if (test(n, N, line)) {
        result = "YES";
        break;
      }
      n++;
    }
    std::cout << result << std::endl;
    T--;
  }
  return 0;
}
