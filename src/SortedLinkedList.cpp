#include "SortedLinkedList.h"
#include <iostream>

SortedLinkedList::SortedLinkedList() : head(nullptr) {}

SortedLinkedList::~SortedLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void SortedLinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

bool SortedLinkedList::search(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void SortedLinkedList::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null\n";
}
