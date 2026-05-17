#include "stack.h"
#include <iostream>

// 建構子
Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity];
    top = -1;
}

// 解構子（避免 memory leak）
Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (isFull()) {
        std::cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = x;
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow\n";
        return;
    }
    top--;
}

int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

int Stack::size() {
    return top + 1;
}