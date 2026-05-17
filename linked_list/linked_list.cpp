#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
    count = 0;
}

// destructor：避免 memory leak
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// 插入頭部
void LinkedList::insertFront(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    count++;
}

// 插入尾部
void LinkedList::insertBack(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    count++;
}

// 刪除指定值
void LinkedList::deleteValue(int x) {
    if (head == nullptr) return;

    // 如果是頭
    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != x) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    count--;
}

// 搜尋
bool LinkedList::search(int x) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == x) return true;
        temp = temp->next;
    }

    return false;
}

// 印出
void LinkedList::display() {
    Node* temp = head;

    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "NULL\n";
}

// size
int LinkedList::size() {
    return count;
}