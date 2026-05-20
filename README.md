# cpp-sys-toolkit

> A modular C++ systems programming toolkit for studying core backend and OS-level concepts.

---

## Overview

cpp-sys-toolkit is a systems programming project that implements fundamental backend components using modern C++.

It focuses on:
- Performance-critical design
- Concurrency handling
- Memory management
- Low-level system architecture

The goal is to demonstrate **how core system components are built from scratch**, not just used.

---

## Features

### LRU Cache (O(1))
- Hash map + doubly linked list design
- O(1) get / put operations
- LRU eviction strategy

### Thread Pool
- Fixed-size worker threads
- Task queue with mutex + condition_variable
- Concurrent task execution

### Memory Pool Allocator
- Preallocated memory blocks
- Free list management
- O(1) allocation / deallocation
- Reduced memory fragmentation

---

## System Design

```
LRU Cache
   ↓
Thread Pool
   ↓
Memory Pool Allocator
```

Each module is:
- Independent
- Reusable
- Designed for system-level scalability

---

## Project Structure

```
cpp-sys-toolkit/
│
├── CMakeLists.txt
├── README.md
│
├── include/
├── src/
│
├── examples/
│   ├── lru_example.cpp
│   ├── thread_example.cpp
│   └── memory_example.cpp
│
└── build/
```

---

## Build

```bash
mkdir build
cd build
cmake ..
mingw32-make
```

---

##  Run Examples

```bash
./lru_example
./thread_example
./memory_example
```

---

## Key Concepts

- Data structures (LRU Cache design)
- Multithreading (Thread Pool)
- Memory management (Custom allocator)
- RAII and resource safety
- Low-level system design in C++
- Modular architecture with CMake

---

## Future Work

- Lock-free queue implementation
- Object pool allocator
- Benchmark suite (performance comparison)
- Linux epoll-based network server
- Memory profiling tools

---

## Author

Built by: Hubert Kuo  
Focus: Computer Vision / AI Systems / Machine Learning