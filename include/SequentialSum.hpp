#pragma once
#include <vector>
using namespace std;

class SequentialSum {
private:
    const vector<int>& data; 

public:
    SequentialSum(const vector<int>& input);
    long long Compute() const;
    double Benchmark(int run = 5) const;
};