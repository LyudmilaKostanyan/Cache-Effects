#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <iomanip>

constexpr size_t ARRAY_SIZE = 64 * 1024 * 1024;
constexpr int ITERATIONS = 100;
int STEPS[] = {1, 16, 64, 256, 1024, 4096};

void measure_access_time(int stride) {
    int* array = new int[ARRAY_SIZE / sizeof(int)];
    volatile int sum = 0;
    std::vector<double> times;

    for (size_t i = 0; i < ARRAY_SIZE / sizeof(int); ++i) {
        array[i] = i;
    }

    for (int iter = 0; iter < ITERATIONS; ++iter) {
        auto start = std::chrono::high_resolution_clock::now();

        for (size_t i = 0; i < (ARRAY_SIZE / sizeof(int)) / (4096 / stride); i += stride) {
            sum += array[i];
        }

        auto end = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        times.push_back(elapsed);
    }

    double avg_time = std::accumulate(times.begin(), times.end(), 0.0) / times.size();
    
    std::cout << std::setw(10) << stride << " | " 
              << std::setw(15) << std::fixed << std::setprecision(2) << avg_time << " ns\n";

    delete[] array;
}

int main() {
    std::cout << "Cache Performance Test\n";
    std::cout << "---------------------------------\n";
    std::cout << std::setw(10) << "Stride" << " | " << std::setw(15) << "Avg Time (ns)\n";
    std::cout << "---------------------------------\n";

    for (int stride : STEPS) {
        measure_access_time(stride);
    }

    return 0;
}
