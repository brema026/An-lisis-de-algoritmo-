#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int value) {
    insertHelper(root, value);
}

void BinarySearchTree::insertHelper(TreeNode*& node, int value) {
    if (!node) {
        node = new TreeNode(value);
    } else if (value < node->data) {
        insertHelper(node->left, value);
    } else {
        insertHelper(node->right, value);
    }
}

bool BinarySearchTree::search(int value) const {
    return searchHelper(root, value);
}

bool BinarySearchTree::searchHelper(TreeNode* node, int value) const {
    if (!node) return false;
    if (value == node->data) return true;
    else if (value < node->data) return searchHelper(node->left, value);
    else return searchHelper(node->right, value);
}