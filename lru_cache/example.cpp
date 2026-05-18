#include "include/lru_cache.h"
#include <iostream>

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << cache.get(1) << std::endl; // 10

    cache.put(3, 30); // evict 2

    std::cout << cache.get(2) << std::endl; // -1
}