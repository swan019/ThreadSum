#include "SequentialSum.hpp"
#include <chrono>
#include <numeric>
using namespace std;
using namespace chrono;

SequentialSum::SequentialSum(const vector<int>& input) : data(input) {}

//Simple Sum
long long SequentialSum::Compute() const {
    return accumulate(data.begin(), data.end(), 0LL);
}

// Runs multiple trials and returns average time
double SequentialSum::Benchmark(int runs) const {
    double Total_time = 0;

    for(int i = 0; i < runs; ++i){

        auto start = high_resolution_clock::now();
        Compute(); //ignore result during benchmark
        auto end = high_resolution_clock::now();

        Total_time += duration<double>(end-start).count();
    }

    return Total_time / runs;
}