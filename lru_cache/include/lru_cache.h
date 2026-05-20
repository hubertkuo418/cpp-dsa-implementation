#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>

/*
 * LRUCache
 * --------
 * Implements a Least Recently Used (LRU) cache using:
 * - Hash map (unordered_map) for O(1) key lookup
 * - Doubly linked list for O(1) insertion and deletion order tracking
 *
 * Most recently used items are moved to the front of the list,
 * while least recently used items are evicted from the back.
 */
class LRUCache {
private:
    /*
     * Node
     * ----
     * Represents a single entry in the doubly linked list.
     */
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v);
    };

    int capacity;  // Maximum number of elements allowed in cache

    // Hash map: key -> pointer to node in doubly linked list
    std::unordered_map<int, Node*> cache;

    // Dummy head and tail nodes to simplify edge operations
    Node* head;
    Node* tail;

    /*
     * Remove a node from the doubly linked list.
     * Does not free memory.
     */
    void remove(Node* node);

    /*
     * Insert a node right after the head (mark as most recently used).
     */
    void insertFront(Node* node);

public:
    /*
     * Constructor
     * Initializes cache with given capacity.
     */
    LRUCache(int cap);

    /*
     * Destructor
     * Frees all allocated memory.
     */
    ~LRUCache();

    /*
     * Retrieve value by key.
     * Returns -1 if key does not exist.
     */
    int get(int key);

    /*
     * Insert or update key-value pair.
     * Evicts least recently used item if capacity is exceeded.
     */
    void put(int key, int value);
};

#endif