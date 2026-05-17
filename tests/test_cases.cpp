#include <iostream>
#include <cassert>

#include "stack/stack.h"
#include "queue/queue.h"
#include "linked_list/linked_list.h"
#include "bst/bst.h"

void test_stack() {
    Stack s(3);

    s.push(1);
    s.push(2);

    assert(s.peek() == 2);
    assert(s.size() == 2);

    s.pop();
    assert(s.peek() == 1);

    std::cout << "Stack test passed\n";
}

void test_queue() {
    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);

    assert(q.getFront() == 10);
    assert(q.getRear() == 20);

    q.dequeue();
    assert(q.getFront() == 20);

    std::cout << "Queue test passed\n";
}

void test_linked_list() {
    LinkedList list;

    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);

    assert(list.size() == 3);
    assert(list.search(2) == true);

    list.deleteValue(2);
    assert(list.search(2) == false);

    std::cout << "Linked List test passed\n";
}

void test_bst() {
    BST tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    assert(tree.search(10) == true);
    assert(tree.search(100) == false);

    std::cout << "BST test passed\n";
}

int main() {
    std::cout << "Running tests...\n\n";

    test_stack();
    test_queue();
    test_linked_list();
    test_bst();

    std::cout << "\nAll tests passed!\n";

    return 0;
}