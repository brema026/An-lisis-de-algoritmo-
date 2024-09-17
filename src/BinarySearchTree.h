#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void inOrderTraversal();

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    void insert(Node*& node, int value);
    void inOrderTraversal(Node* node);
    void destroyTree(Node* node);
};

#endif
