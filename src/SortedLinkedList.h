#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#pragma once

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
public:
    SortedLinkedList();
    ~SortedLinkedList();
    void insert(int value);
    bool search(int value) const;
    void display() const;
private:
    Node* head;
};

#endif
