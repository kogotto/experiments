#include <string>
#include <benchmark/benchmark.h>

#include "work.h"


namespace {

void benchHelloWorld(benchmark::State& state) {
    const std::string someBigString("abcdefghjklmnopqrstuvwxyz");
    for (auto _ : state) {
        std::string localCopy = someBigString;
    }
}

void benchWork(benchmark::State& state) {
    for (auto _ : state) {
        work("input", "output");
    }
}

void properBenchWork(benchmark::State& state) {
    for (int i = 0; state.KeepRunning(); ++i) {
        work("input", "out/" + std::to_string(i));
    }
}

}

/* BENCHMARK(benchHelloWorld); */
/* BENCHMARK(benchWork); */
BENCHMARK(properBenchWork);
BENCHMARK_MAIN();
