#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#pragma once

class BinarySearchTree {
public:
    BinarySearchTree();
    void insert(int value);
    bool search(int value) const;
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;
    void insertHelper(TreeNode*& node, int value);
    bool searchHelper(TreeNode* node, int value) const;
};

#endif
