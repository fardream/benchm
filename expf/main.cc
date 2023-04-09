#include <math.h>

#include <iostream>
#include <vector>
int main(int argc, char** argv) {
  constexpr const int N = 1000000000;
  float x = 0;

  std::vector<float> d(N, 0);
  for (int i = 0; i < N; i++) {
    d[i] = -float(i);
  }

  for (int i = 0; i < N; i++) {
    x += expf(d[i]);
  }

  std::cout << x << std::endl;
  return 0;
}
