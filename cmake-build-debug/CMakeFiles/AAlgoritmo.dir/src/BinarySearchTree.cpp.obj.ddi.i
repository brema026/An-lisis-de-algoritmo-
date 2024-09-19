# 0 "C:/Users/Brene/OneDrive/Escritorio/AAlgoritmo/src/BinarySearchTree.cpp"
# 1 "C:\\Users\\Brene\\OneDrive\\Escritorio\\AAlgoritmo\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/Brene/OneDrive/Escritorio/AAlgoritmo/src/BinarySearchTree.cpp"
# 1 "C:/Users/Brene/OneDrive/Escritorio/AAlgoritmo/src/BinarySearchTree.h" 1



       

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
# 2 "C:/Users/Brene/OneDrive/Escritorio/AAlgoritmo/src/BinarySearchTree.cpp" 2


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
