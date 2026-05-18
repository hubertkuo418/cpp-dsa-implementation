cmake_minimum_required(VERSION 3.15)
project(cpp_sys_toolkit)

set(CMAKE_CXX_STANDARD 17)

# -------------------------
# LRU Cache
# -------------------------
add_library(lru_cache
    lru_cache/src/lru_cache.cpp
)

target_include_directories(lru_cache PUBLIC
    lru_cache/include
)

# -------------------------
# Thread Pool
# -------------------------
add_library(thread_pool
    thread_pool/src/thread_pool.cpp
)

target_include_directories(thread_pool PUBLIC
    thread_pool/include
)

# -------------------------
# Memory Pool
# -------------------------
add_library(memory_pool
    memory_pool/src/memory_pool.cpp
)

target_include_directories(memory_pool PUBLIC
    memory_pool/include
)

# -------------------------
# Examples
# -------------------------
add_executable(lru_example
    lru_cache/example.cpp
)

target_link_libraries(lru_example lru_cache)

add_executable(thread_example
    thread_pool/example.cpp
)

target_link_libraries(thread_example thread_pool)

add_executable(memory_example
    memory_pool/example.cpp
)

target_link_libraries(memory_example memory_pool)