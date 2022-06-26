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

bool isBalanced(TreeNode* root) {
    auto is_balanced = [](const auto& self, TreeNode* root, int& height) -> bool {
        if (!root) return true;

        int left_height = 0, right_height = 0;
        auto left_balanced = self(self, root->left, left_height);
        auto right_balanced = self(self, root->right, right_height);

        height = std::max(left_height, right_height) + 1;
        return left_balanced && right_balanced && std::abs(left_height - right_height) <= 1;
    };

    int height = 0;
    return is_balanced(is_balanced, root, height);
}