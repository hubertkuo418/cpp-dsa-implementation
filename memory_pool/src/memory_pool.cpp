#include "../include/memory_pool.h"
#include <iostream>

/*
 * MemoryPool Constructor
 * Initializes a fixed-size memory pool and builds a free list
 * for efficient memory allocation.
 */
MemoryPool::MemoryPool(size_t blockSize, size_t blockCount) {
    this->blockSize = blockSize;
    this->blockCount = blockCount;

    // Allocate a continuous memory block
    pool = new char[blockSize * blockCount];

    // Initialize free list pointer
    freeList = nullptr;

    // Build the free list by splitting the pool into blocks
    for (size_t i = 0; i < blockCount; i++) {

        // Treat each block as a FreeBlock structure
        FreeBlock* block = (FreeBlock*)(pool + i * blockSize);

        // Insert block into the front of the free list
        block->next = freeList;
        freeList = block;
    }
}

/*
 * allocate
 * Returns a pointer to a free memory block.
 * If no blocks are available, returns nullptr.
 */
void* MemoryPool::allocate() {
    if (!freeList) {
        return nullptr; // Out of memory
    }

    // Take the first available block
    FreeBlock* block = freeList;
    freeList = freeList->next;

    return block;
}

/*
 * deallocate
 * Returns a previously allocated block back to the free list.
 */
void MemoryPool::deallocate(void* ptr) {
    // Cast pointer back to FreeBlock
    FreeBlock* block = (FreeBlock*)ptr;

    // Insert block back into free list
    block->next = freeList;
    freeList = block;
}

/*
 * Destructor
 * Releases the entire memory pool.
 */
MemoryPool::~MemoryPool() {
    delete[] pool;
}