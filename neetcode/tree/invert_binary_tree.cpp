//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    auto inverted_left = invertTree(root->left);
    auto inverted_right = invertTree(root->right);

    root->left = inverted_right;
    root->right = inverted_left;

    return root;
}