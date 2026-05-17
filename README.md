# cpp-dsa-implementation

A C++ implementation of fundamental data structures and graph traversal algorithms for learning and interview preparation.

---

## Overview

This project implements core data structures from scratch using C++:

- Stack (Array-based)
- Queue (Circular Queue)
- Linked List (Singly Linked List)
- Binary Search Tree (BST)
- Graph Traversal (DFS / BFS)

---

## Project Structure

```
cpp-data-structure/
├── main.cpp
├── stack/
├── queue/
├── linked_list/
├── bst/
├── graph_traversal/
└── tests/
```

---

## Data Structures

### Stack
- push / pop / peek
- isEmpty / isFull
- O(1) operations

### Queue (Circular)
- enqueue / dequeue
- front / rear
- efficient space usage with modulo indexing

### Linked List
- insertFront / insertBack
- deleteValue / search
- dynamic memory with pointers

### Binary Search Tree (BST)
- insert / search
- inorder / preorder / postorder traversal
- average O(log n)

### Graph Traversal
- DFS (recursion)
- BFS (queue)
- adjacency list representation

---

## Complexity Summary

| Structure | Operation | Complexity |
|----------|----------|------------|
| Stack | push/pop | O(1) |
| Queue | enqueue/dequeue | O(1) |
| Linked List | insert/delete | O(n) |
| BST | search/insert | O(log n) avg |
| Graph | DFS/BFS | O(V + E) |

---

## How to Run

```bash
g++ main.cpp graph_traversal/dfs_bfs.cpp bst/bst.cpp stack/stack.cpp queue/queue.cpp linked_list/linked_list.cpp -o main
./main
```

---

## Goal

- Strengthen C++ fundamentals
- Practice pointer and memory management
- Prepare for CS interviews and internships

