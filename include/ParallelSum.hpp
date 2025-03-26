#pragma once
#include <vector>
#include <atomic>
#include <thread>
using namespace std;

class ParallelSum {
private:
    const vector<int>& data;
    atomic<long long> Total_Sum{0};

    //thread work function
    void Partial_Sum(int start, int end);

    //detect available CPU cores
    int Detect_Thread_Count() const;

public:
    explicit ParallelSum(const vector<int>& input);
    long long Compute();
    double Benchmark(int runs = 5);
};

/*

---> long long Compute();

This function performs parallel summation using multiple threads, 
where each thread calculates a portion (chunk) of the sum, and the 
results are combined.

Total_Sum is an atomic variable (shared across threads) that stores the final sum.

---> int Detect_Thread_Count() const;
detect_thread_count() to determine how many threads should be used.
Typically, this is based on the number of CPU cores for maximum efficiency.

*/