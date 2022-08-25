//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//
#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
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

void branchSums(BinaryTree* root, int currentSum, vector<int>& sums) {
    if (!root)  {
        return;
    }
    currentSum += root->value;

    if (!root->left && !root->right) {
        sums.emplace_back(currentSum);
        return;
    }

    branchSums(root->left, currentSum, sums);
    branchSums(root->right, currentSum, sums);
}

vector<int> branchSums(BinaryTree *root) {
    vector<int> res;
    branchSums(root, 0, res);
    return res;
}
