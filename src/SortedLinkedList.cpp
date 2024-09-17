#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList() : head(nullptr), tail(nullptr) {}

SortedLinkedList::~SortedLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void SortedLinkedList::insert(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else if (value <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (value >= tail->data) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

bool SortedLinkedList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SortedLinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
