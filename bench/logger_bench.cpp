#include <benchmark/benchmark.h>
#include "logger/console_logger.h"

static void BM_Logging(benchmark::State &state)
{
    ConsoleLogger logger;
    for (auto _ : state)
    {
        logger.log("Hello, World!");
    }
}

// This macro registers the BM_Put function as a benchmark with Google Benchmark's runtime system
// Ensuring that when the benchmark executables runs, BM_Put will be discovered and executed
BENCHMARK(BM_Logging);