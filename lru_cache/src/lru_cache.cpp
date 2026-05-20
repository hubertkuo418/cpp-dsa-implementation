#include "../include/lru_cache.h"

/*
 * Node constructor
 * Initializes a doubly linked list node used in the LRU cache.
 */
LRUCache::Node::Node(int k, int v) {
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}

/*
 * LRUCache constructor
 * Initializes cache with a fixed capacity and creates
 * dummy head and tail nodes to simplify list operations.
 */
LRUCache::LRUCache(int cap) {
    capacity = cap;

    // Create sentinel nodes (dummy head and tail)
    head = new Node(0, 0);
    tail = new Node(0, 0);

    // Initialize empty doubly linked list structure
    head->next = tail;
    tail->prev = head;
}

/*
 * Destructor
 * Frees all dynamically allocated nodes in the doubly linked list.
 */
LRUCache::~LRUCache() {
    Node* cur = head;

    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

/*
 * Remove a node from the doubly linked list.
 * Does NOT delete the node itself.
 */
void LRUCache::remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

/*
 * Insert a node right after the head (most recently used position).
 */
void LRUCache::insertFront(Node* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

/*
 * Retrieve value by key.
 * If key exists, move node to front (mark as recently used).
 */
int LRUCache::get(int key) {
    if (cache.find(key) == cache.end()) {
        return -1;
    }

    Node* node = cache[key];

    // Move accessed node to front (MRU position)
    remove(node);
    insertFront(node);

    return node->value;
}

/*
 * Insert or update key-value pair.
 * If key exists, update value and move to front.
 * If cache is full, evict least recently used (tail->prev).
 */
void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;

        remove(node);
        insertFront(node);
        return;
    }

    // Evict least recently used item if capacity is reached
    if (cache.size() == capacity) {
        Node* lru = tail->prev;

        cache.erase(lru->key);
        remove(lru);
        delete lru;
    }

    // Insert new node at front (most recently used)
    Node* newNode = new Node(key, value);
    cache[key] = newNode;
    insertFront(newNode);
}