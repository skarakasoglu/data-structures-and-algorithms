//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//
#include <cmath>

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
    if (!tree) return std::numeric_limits<int>::max();

    int diff = std::abs(tree->value - target);
    int sub_closest;
    if (target >= tree->value) {
        sub_closest = findClosestValueInBst(tree->right, target);
    } else {
        sub_closest = findClosestValueInBst(tree->left, target);
    }
    long sub_closest_diff = std::abs((long)sub_closest - target);
    auto result = diff < sub_closest_diff ? tree->value : sub_closest;

    return result;
}
