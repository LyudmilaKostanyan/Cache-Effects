# Cache-Related Performance Experiments

This repository collects several small projects exploring the impact of memory layouts, CPU cache behavior, and cache-aware vs cache-oblivious strategies on performance. All projects focus on how data organization and access patterns influence cache efficiency and program speed.

---

## Projects Overview

### 1. [Vector vs List Insert Performance](vector-vs-list-insert/README.md)

* **Purpose**: Compares `std::vector` and `std::list` for middle insertions.
* **Description**:

  * Measures how insertion performance differs between contiguous (`std::vector`) and linked (`std::list`) memory layouts.
  * Shows that vector insertions can be faster due to better cache locality, even when shifting elements is required.
* **Key Insight**: Contiguous memory often outperforms linked structures for cache-sensitive operations.

---

### 2. [Cache Effect on Container Performance](vector-vs-list-performance/README.md)

* **Purpose**: Compares `std::vector` and `std::list` for sorted insertions and random deletions.
* **Description**:

  * Highlights how memory layout affects cache performance.
  * Vectors benefit from contiguous memory, improving cache line usage and prefetching.
  * Lists suffer from scattered memory, causing more cache misses and slower access.
* **Key Insight**: Cache locality and predictable memory access patterns strongly affect container performance.

---

### 3. [Cache Hierarchy Performance Exploration](Cache-Performance-Test/README.md)

* **Purpose**: Measures memory access times for different stride sizes to analyze cache behavior.
* **Description**:

  * Tests how L1, L2, and L3 caches respond to varying access patterns.
  * Smaller strides show better cache locality; larger strides cause more cache misses.
* **Key Insight**: Memory stride and locality of reference directly influence access time and cache utilization.

---

### 4. [Cache-Aware vs Cache-Oblivious Merge Sort](Cache-Aware-Merge-Sort/README.md)

* **Purpose**: Compares a standard merge sort with a cache-aware version optimized for CPU caches.
* **Description**:

  * Cache-oblivious merge sort works well naturally with hierarchical memory.
  * Cache-aware version processes data in blocks sized to fit the CPU cache.
* **Key Insight**: Cache-aware optimizations do not always improve performance; overhead may offset gains depending on the algorithm and data size.

---

### 5. [Matrix Multiplication Performance Comparison](Matrix-Multiplication-Cache/README.md)

* **Purpose**: Evaluates four matrix multiplication strategies: naive, blocked, recursive, and parallel blocked.
* **Description**:

  * Focuses on cache utilization in matrix multiplication.
  * Blocked and parallel blocked methods are cache-aware, improving memory locality.
  * Recursive method is cache-oblivious, adapting naturally to cache hierarchies.
* **Key Insight**: Combining cache-aware blocking with multithreading yields the best performance for large matrices.

---

### 6. [Matrix Multiplication with Cache Optimization (Transpose)](Matrix-Transpose-Cache/README.md)

* **Purpose**: Explores cache-friendly matrix multiplication using transpose and blocked access.
* **Description**:

  * Implements methods to reduce cache misses in row-major storage.
  * Calculates optimal block size based on L1 cache size, cache line, and associativity.
* **Key Insight**: Optimizing memory access patterns significantly reduces execution time, especially for large matrices.

---

### 7. [Comparing Structure of Arrays (SoA) vs Array of Structures (AoS)](AoS-vs-SoA/README.md)

* **Purpose**: Compares memory layouts for particle simulations: AoS vs SoA.
* **Description**:

  * AoS stores all properties of a particle together; SoA stores each property in its own contiguous array.
  * SoA improves cache usage and enables better SIMD utilization.
* **Key Insight**: For simulations involving large numbers of objects, contiguous property arrays (SoA) are significantly faster due to cache efficiency.


