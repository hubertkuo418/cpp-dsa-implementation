#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);   // 建構子
    ~Stack();          // 解構子（很重要！）

    void push(int x);
    void pop();
    int peek();

    bool isEmpty();
    bool isFull();
    int size();
};

#endif