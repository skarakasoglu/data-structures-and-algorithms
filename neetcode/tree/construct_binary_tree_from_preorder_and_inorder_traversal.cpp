//
// Created by Süleyman Karakaşoğlu on 7.07.2022.
//

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;

    auto root = new TreeNode(preorder[0]);
    auto mid = -1;
    for (auto i = 0; i < inorder.size(); i++) {
        if (inorder[i] == root->val) {
            mid = i;
            break;
        }
    }
    if (mid == -1) return nullptr;

    auto left_inorder = std::vector<int>(inorder.begin(), inorder.begin() + mid);
    auto left_preorder = std::vector<int>(preorder.begin() + 1, preorder.begin() + inorder.size());
    auto right_inorder = std::vector<int>(inorder.begin() + mid + 1, inorder.end());
    auto right_preorder = std::vector<int>(preorder.begin() + left_inorder.size() + 1, preorder.end());

    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);

    return root;
}