#include "../include/memory_pool.h"
#include <iostream>

MemoryPool::MemoryPool(size_t blockSize, size_t blockCount) {
    this->blockSize = blockSize;
    this->blockCount = blockCount;

    pool = new char[blockSize * blockCount];

    freeList = nullptr;

    // 建立 free list
    for (size_t i = 0; i < blockCount; i++) {

        FreeBlock* block = (FreeBlock*)(pool + i * blockSize);
        block->next = freeList;
        freeList = block;
    }
}

void* MemoryPool::allocate() {
    if (!freeList) {
        return nullptr; // out of memory
    }

    FreeBlock* block = freeList;
    freeList = freeList->next;

    return block;
}

void MemoryPool::deallocate(void* ptr) {
    FreeBlock* block = (FreeBlock*)ptr;

    block->next = freeList;
    freeList = block;
}

MemoryPool::~MemoryPool() {
    delete[] pool;
}