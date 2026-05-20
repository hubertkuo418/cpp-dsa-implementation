#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <cstddef>

/**
 * @class MemoryPool
 * @brief A simple fixed-size memory pool allocator for efficient memory management.
 *
 * This class pre-allocates a contiguous block of memory and manages it as a pool
 * of fixed-size blocks. It improves allocation performance by reducing reliance
 * on dynamic heap allocations and minimizing fragmentation.
 */
class MemoryPool {
private:
    /**
     * @struct FreeBlock
     * @brief Internal structure used to build a singly linked list of free memory blocks.
     */
    struct FreeBlock {
        FreeBlock* next;  ///< Pointer to the next free block in the free list
    };

    size_t blockSize;    ///< Size (in bytes) of each block in the pool
    size_t blockCount;   ///< Total number of blocks in the pool

    char* pool;          ///< Pointer to the raw allocated memory pool
    FreeBlock* freeList; ///< Head pointer of the free list

public:
    /**
     * @brief Constructs a memory pool with fixed block size and count.
     * @param blockSize Size of each memory block in bytes
     * @param blockCount Number of blocks to allocate in the pool
     */
    MemoryPool(size_t blockSize, size_t blockCount);

    /**
     * @brief Destructor that releases the allocated memory pool.
     */
    ~MemoryPool();

    /**
     * @brief Allocates a block of memory from the pool.
     * @return Pointer to allocated memory block, or nullptr if pool is exhausted
     */
    void* allocate();

    /**
     * @brief Returns a previously allocated block back to the pool.
     * @param ptr Pointer to memory block to be deallocated
     */
    void deallocate(void* ptr);
};

#endif