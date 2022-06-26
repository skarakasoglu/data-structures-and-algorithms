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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return -1;

        auto left = diameterOfBinaryTree(root->left);
        auto right = diameterOfBinaryTree(root->right);

        auto height = 1 + std::max(left, right);
        auto diameter = left + right + 2;

        return diameter;
    }
};