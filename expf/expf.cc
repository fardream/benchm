#include <benchmark/benchmark.h>
#include <math.h>

#include <cstdio>

thread_local std::vector<float> vs;
constexpr const int N = 1000000000;
static void DoSetup(const benchmark::State &state) {
  vs.resize(N, 0);
  for (int i = 0; i < N; i++) {
    vs[i] = -(float)(i);
  }
}

static void BM_expf(benchmark::State &state) {
  for (auto _ : state) {
    float x = 0;
    for (int i = 0; i < N; i++) {
      x += expf(vs[i]);
    }
    std::printf("%f", x);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_expf)->Setup(DoSetup);
// Run the benchmark
BENCHMARK_MAIN();
