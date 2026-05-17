#include "queue.h"
#include <iostream>

// constructor
Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

// destructor
Queue::~Queue() {
    delete[] arr;
}

// enqueue
void Queue::enqueue(int x) {
    if (isFull()) {
        std::cout << "Queue Overflow\n";
        return;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

// dequeue
void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue Underflow\n";
        return;
    }

    front = (front + 1) % capacity;
    count--;
}

// front element
int Queue::getFront() {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

// rear element
int Queue::getRear() {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return arr[rear];
}

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == capacity;
}

int Queue::size() {
    return count;
}