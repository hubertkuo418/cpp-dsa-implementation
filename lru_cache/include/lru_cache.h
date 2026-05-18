#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v);
    };

    int capacity;
    std::unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    void remove(Node* node);
    void insertFront(Node* node);

public:
    LRUCache(int cap);
    ~LRUCache();

    int get(int key);
    void put(int key, int value);
};

#endif