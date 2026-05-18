# cpp-sys-toolkit

A modular C++ systems programming toolkit implementing core components of caching, concurrency, and memory management.

---

## Overview

This project demonstrates fundamental system-level components used in backend systems, OS concepts, and performance-critical applications.

Focus: **low-level design, performance, and concurrency in modern C++**.

---

## Components

### 1. LRU Cache (O(1))
- Hash map + doubly linked list
- O(1) get / put operations
- LRU eviction policy

### 2. Thread Pool
- Fixed-size worker threads
- Task queue (mutex + condition_variable)
- Concurrent task execution

### 3. Memory Pool Allocator
- Preallocated memory blocks
- Free list management
- O(1) allocate / deallocate
- Reduced fragmentation

---

## Architecture

LRU Cache → Thread Pool → Memory Pool

Each module is independent and reusable.

---

## Build

```bash
cmake ..
mingw32-make
```

---

## Run Examples

```bash
./lru_example
./thread_example
./memory_example
```

---

## Key Concepts

- Data structures (LRU Cache)
- Concurrency (Thread Pool)
- Memory management (Memory Pool)
- RAII and resource safety
- Modular CMake project design

---

## Why this matters

Shows ability to:
- Design system-level components
- Handle multithreading safely
- Manage memory manually
- Structure scalable C++ projects

---

## Future Work

- Lock-free queue
- Object pool allocator
- Benchmark suite
- Linux epoll server

---

##  Author

C++ systems programming practice project for backend / embedded / IC preparation.

