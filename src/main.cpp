#include "ParallelSum.hpp"
#include "SequentialSum.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

// Generates random data
vector<int> generate_data(size_t size){
    vector<int> data(size);
    for(auto& num : data){
        num = rand() % 10 + 1;
    }
    return data;
}

// Pretty-prints results
void print_results(const std::string& name, double time, long long sum) {
     cout << "┌──────────────────────────────┐\n"
          << "│ " << std::left << std::setw(28) << name << "│\n"
          << "├──────────────────────────────┤\n"
          << "│ Sum: " << std::setw(21) << sum << " │\n"
          << "│ Time: " << std::setw(20) << time << "s │\n"
          << "└──────────────────────────────┘\n";
}

int main() {
    const size_t data_size = 100'000'000;
    auto data = generate_data(data_size);

    cout << "Benchmarking with " << data_size << " elements...\n\n";


    //Sequential Test
    SequentialSum seq(data);
    auto seq_Time = seq.Benchmark();
    auto seq_Result = seq.Compute();
    print_results("SEQUENTIAL SUM", seq_Time, seq_Result);

    //Parallel Test
    ParallelSum par(data);
    auto par_Time = par.Benchmark();
    auto par_Result = par.Compute();
    print_results("PARALLEL SUM", par_Time, par_Result);

    //Calculate speedup
    double speedup = seq_Time / par_Time;
    cout << "\nParallel version is " << fixed << setprecision(1) 
            << speedup << "x faster!\n";
    
    return 0;
}