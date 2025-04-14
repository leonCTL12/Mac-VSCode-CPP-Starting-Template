#include <benchmark/benchmark.h>
#include "calculator/calculator.h"

static void BM_Calculate(benchmark::State &state)
{
    Calculator calculator;
    for (auto _ : state)
    {
        calculator.add(1.0, 2.0);
    }
}

// This macro registers the BM_Put function as a benchmark with Google Benchmark's runtime system
// Ensuring that when the benchmark executables runs, BM_Put will be discovered and executed
BENCHMARK(BM_Calculate);