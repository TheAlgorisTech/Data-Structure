# Queue Contiguously-Allocated Structure 
- Composed of single slabs of memory
- Includes *Arrays, matrices, heaps & hash table*


### Pros
- Constant-time access given the index
- Space efficiency
- Memory locality

### Cons
- Cannot adjust size in the middle of a program's execution
- Allocating large arrays, can waste space
