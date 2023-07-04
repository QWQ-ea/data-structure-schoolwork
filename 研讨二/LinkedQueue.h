#pragma once
#include"task.h"
template <typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T _data) : data(_data), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    LinkedQueue() : head(nullptr), tail(nullptr) {}
    ~LinkedQueue() { clear(); }
    void push(T data);
    void pop();
    T front();
    T back();
    bool empty();
    int size();
    void clear();
};

template <typename T>
void LinkedQueue<T>::push(T data) {
    Node* new_node = new Node(data);
    if (tail == nullptr) {
        head = new_node;
    }
    else {
        tail->next = new_node;
    }
    tail = new_node;
}

template <typename T>
void LinkedQueue<T>::pop() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

template <typename T>
T LinkedQueue<T>::front() {
    return head->data;
}

template <typename T>
T LinkedQueue<T>::back() {
    return tail->data;
}

template <typename T>
bool LinkedQueue<T>::empty() {
    return head == nullptr;
}

template <typename T>
int LinkedQueue<T>::size() {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        count++;
    }
    return count;
}
template <typename T>
void LinkedQueue<T>::clear() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    head = tail = nullptr;
}

