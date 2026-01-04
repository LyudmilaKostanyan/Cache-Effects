#include <iostream>
#include <vector>
#include <list>
#include <chrono>

void pre_allocated_vector_insert(size_t num_insertions) {
    std::vector<int> vec;
    vec.reserve(num_insertions);
    for (size_t i = 0; i < num_insertions; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }
}

void vector_insert(size_t num_insertions) {
    std::vector<int> vec;
    for (size_t i = 0; i < num_insertions; ++i) {
        vec.insert(vec.begin() + vec.size() / 2, i);
    }
}

void list_insert(size_t num_insertions) {
    std::list<int> lst;
    auto it = lst.begin();
    for (size_t i = 0; i < num_insertions; ++i) {
        it = lst.insert(std::next(lst.begin(), lst.size() / 2), i);
    }
}

int main() {
    constexpr size_t num_insertions = 10000;

    auto start = std::chrono::high_resolution_clock::now();
    pre_allocated_vector_insert(num_insertions);
    auto end = std::chrono::high_resolution_clock::now();
    double pre_allocated_vector_time = std::chrono::duration<double, std::milli>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    vector_insert(num_insertions);
    end = std::chrono::high_resolution_clock::now();
    double vector_insert_time = std::chrono::duration<double, std::milli>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    list_insert(num_insertions);
    end = std::chrono::high_resolution_clock::now();
    double list_insert_time = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Operation                Execution Time (ms)\n";
    std::cout << "--------------------------------------------\n";
    std::cout << "Pre-allocated Vector      " << pre_allocated_vector_time << "\n";
    std::cout << "Vector Insert             " << vector_insert_time << "\n";
    std::cout << "List Insert               " << list_insert_time << "\n";

    return 0;
}
