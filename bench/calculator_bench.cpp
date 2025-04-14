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

static void BM_CalculateMore(benchmark::State &state)
{
    Calculator calculator;
    for (auto _ : state)
    {
        calculator.add(1.0, 2.0);
        calculator.add(3.0, 4.0);
        calculator.add(5.0, 6.0);
    }
}

// Ensuring that when the benchmark executables runs, BM_Put will be discovered and executed
BENCHMARK(BM_Calculate);
BENCHMARK(BM_CalculateMore);