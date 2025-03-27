# ⚡ ThreadSum - Parallel Array Summation

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![MultiThreaded](https://img.shields.io/badge/Threads-8_Cores-orange.svg)

Blazing-fast parallel summation of large arrays using C++ threads. Achieve **4x speedup** by utilizing all CPU cores!

## 🌟 Features

- **Automatic core detection** - Uses `std::thread::hardware_concurrency()`
- **Thread-safe summation** - `std::atomic` for race-condition-free results
- **Benchmark mode** - Compare sequential vs parallel performance
- **Simple API** - Just 3 lines of code to get started

## 🚀 Quick Start

### Prerequisites
- C++17 compiler (GCC/Clang/MSVC)
- CMake 3.10+

### Build & Run
```bash
# Clone the repository
git clone https://github.com/swan019/ThreadSum.git
cd ThreadSum

# Build with CMake
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Run benchmark
./sum_benchmark

```

# ⚡ ThreadSum - Parallel Array Summation

*Benchmark results showing 4x speedup*

## 🚀 Features
<div align="center">
  <!-- <img src="image/Result.png" width="700" alt="Thread workflow"> -->
  <img src="Image\Output.png" width="700" alt="Thread workflow">
</div>



<div> 

</div>

## 📚 How It Works
- Divides array equally among available CPU cores

- Each thread computes partial sum independently

- Atomic operations safely combine results

- Built-in benchmark compares approaches

## ⚠️ Limitations
- Best for arrays >100,000 elements

- Performance depends on CPU workload

- Not suitable for very small arrays


## 🌱 Learning Outcomes
- Thread synchronization tradeoffs

- Hardware-level performance factors

- Parallel algorithm design patterns

- Modern C++ concurrency APIs