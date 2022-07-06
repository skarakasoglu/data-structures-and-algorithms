//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root, long left_val, long right_val) {
    if (!root) return true;
    else if (root->val <= left_val || root->val >= right_val) {
        return false;
    }

    return isValidBST(root->left, left_val, root->val) && isValidBST(root->right, root->val, right_val);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
}