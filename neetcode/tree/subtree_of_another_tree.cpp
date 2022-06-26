//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool is_sub_tree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;

    if (subRoot->val == root->val) {
        auto is_left = is_sub_tree(root->left, subRoot->left);
        auto is_right = is_sub_tree(root->right, subRoot->right);
        return is_left && is_right;
    } else {
        return false;
    }
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;

    if (is_sub_tree(root, subRoot)) {
        return true;
    }

    auto from_left = isSubtree(root->left, subRoot);
    auto from_right = isSubtree(root->right, subRoot);

    return from_left || from_right;
}