# Vector vs List Insert Performance Comparison

## Project Overview
This project compares the performance of two standard data structures in C++: ```std::vector<int>``` and ```std::list<int>```, focusing on the time taken to perform 10,000 insertions in the middle of each container. The purpose is to understand the performance differences when repeatedly inserting new elements at the middle of both containers and to explore why std::vector may outperform ```std::list```, despite the need for element shifts.

Additionally, an experiment with a pre-allocated vector is included to assess if pre-allocating memory can improve performance by reducing the number of reallocations required during the insertions.

### Expected Outcome
- ```std::vector``` may outperform ```std::list``` in this test, as although vector insertions require shifting elements, the overhead of pointer manipulation in a list (especially when there are many nodes) might be more expensive.
- Pre-allocating a vector could improve performance by reducing reallocations, which are costly in the non-pre-allocated vector.

## Features
1. Sequential Execution:
The program measures and compares the time taken to perform 10,000 insertions in the middle of both ```std::vector<int>``` and ```std::list<int>```.
2. Pre-allocated Vector:
A pre-allocated vector is used with an initial capacity large enough to avoid reallocations during the insertions.
3. Performance Comparison:
Execution time for each insertion approach is measured and displayed.

## Example Output
After running the program, you will see an output similar to this:

```
Operation                Execution Time (ms)
--------------------------------------------
Pre-allocated Vector      4.0728
Vector Insert             3.7693
List Insert               129.871
```

## Performance Considerations
### Why Vector Might Be Faster Than List
- Vector: Even though insertion requires shifting elements, std::vector benefits from contiguous memory storage and better cache locality, making it faster overall for operations like random access and iteration.
- List: ```std::list``` avoids shifting elements, but the overhead of pointer manipulation (especially with a large number of nodes) can lead to slower performance in terms of both time and memory access patterns.

## How to Compile and Run the Code

1. **Clone the repository:**
   If you haven't cloned the repository yet, do so by running:
   ```bash
   git clone https://github.com/LyudmilaKostanyan/vector-vs-list-insert.git
   cd False-Sharing
   ```

2. **Build the project:**
   Once you're in the project directory, compile the code with:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

3. **Run the compiled executable:**
   After compiling, you can run the program:
   ```bash
   cd build
   ./main
   ```

