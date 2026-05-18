#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <cstddef>

class MemoryPool {
private:
    struct FreeBlock {
        FreeBlock* next;
    };

    size_t blockSize;
    size_t blockCount;

    char* pool;        // raw memory
    FreeBlock* freeList;

public:
    MemoryPool(size_t blockSize, size_t blockCount);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* ptr);
};

#endif