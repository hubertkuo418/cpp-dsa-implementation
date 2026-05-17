#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int x);
    void dequeue();

    int getFront();
    int getRear();

    bool isEmpty();
    bool isFull();
    int size();
};

#endif