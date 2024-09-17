#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <iostream>

class SortedLinkedList {
public:
    SortedLinkedList();
    ~SortedLinkedList();

    void insert(int value);
    bool search(int value);
    void display();

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
};

#endif
