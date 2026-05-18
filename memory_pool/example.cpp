#include "include/memory_pool.h"
#include <iostream>

int main() {

    MemoryPool pool(32, 5);

    void* a = pool.allocate();
    void* b = pool.allocate();

    std::cout << "Allocated: " << a << std::endl;
    std::cout << "Allocated: " << b << std::endl;

    pool.deallocate(a);
    pool.deallocate(b);

    void* c = pool.allocate();

    std::cout << "Reused: " << c << std::endl;

    return 0;
}