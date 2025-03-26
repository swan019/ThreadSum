#include "ParallelSum.hpp"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Constructor
ParallelSum::ParallelSum(const std::vector<int>& input) : data(input) {}

// Thread work function
void ParallelSum::Partial_Sum(int start, int end) {
    long long local_sum = 0;
    for(int i = start; i < end; ++i){
        local_sum += data[i];
    }
    Total_Sum += local_sum; // Atomic update
}

int ParallelSum::Detect_Thread_Count() const {
    int threads = std::thread::hardware_concurrency();
    return threads > 0 ? threads : 4;
}


// Main computation
long long ParallelSum::Compute() {
    Total_Sum = 0;
    const int thread_count = Detect_Thread_Count();
    vector<thread> threads;
    const int chunk_size = data.size() / thread_count;

    //create threads
    for(int i = 0; i < thread_count; ++i){
        int start = i * chunk_size;
        int end = (i == thread_count-1) ? data.size() : start + chunk_size;
        threads.emplace_back(&ParallelSum::Partial_Sum, this, start, end);
    }

    //Wait for complition
    for(auto& t : threads) {
        t.join();
    }

    return Total_Sum.load();
}

double ParallelSum::Benchmark(int runs) {
    double Total_Time = 0;
    for(int i = 0; i < runs; ++i){
        auto start = high_resolution_clock::now();
        Compute();
        auto end = high_resolution_clock::now();
        Total_Time += duration<double>(end-start).count();
    }

    return Total_Time / runs;
}


/*

Calls detect_thread_count() to determine how many threads should be used.
Typically, this is based on the number of CPU cores for maximum efficiency.


threads stores all the worker threads.
chunk_size calculates how many numbers each thread will process.

✅ Use &ClassName::memberFunction when passing member functions to threads.
✅ Pass this so the thread knows which object the function belongs to.
❌ std::ref(partial_sum) won’t work for member functions, only for free functions or functors.


.join() makes the main thread wait until all worker threads complete their sum calculations.

Without .join(), the program might continue execution before all threads finish.


total.load() safely reads the atomic total sum.
Ensures the correct sum is returned after all threads finish.


🔹 The array is divided into equal parts.
🔹 Multiple threads compute their portion in parallel.
🔹 Each thread adds its sum to total.
🔹 Main thread waits for all threads to finish.
🔹 The final sum is returned.

*/