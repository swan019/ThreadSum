cmake_minimum_required(VERSION 3.10)
project(SumBenchmark)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Build executable
add_executable(sum_benchmark
    src/main.cpp
    src/ParallelSum.cpp
    src/SequentialSum.cpp
)

# Enable threading
find_package(Threads REQUIRED)
target_link_libraries(sum_benchmark PRIVATE Threads::Threads)