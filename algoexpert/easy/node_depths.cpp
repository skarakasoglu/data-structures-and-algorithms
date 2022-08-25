//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

int nodeDepths(BinaryTree *root, int current_height) {
    if (!root) return 0;

    return current_height + nodeDepths(root->left, current_height + 1) +
            nodeDepths(root->right, current_height + 1);
}

int nodeDepths(BinaryTree *root) {
    return nodeDepths(root, 0);
}
