#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int count;

public:
    LinkedList();
    ~LinkedList();

    void insertFront(int x);
    void insertBack(int x);
    void deleteValue(int x);

    bool search(int x);
    void display();
    int size();
};

#endif