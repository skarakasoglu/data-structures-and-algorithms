//
// Created by Süleyman Karakaşoğlu on 6.07.2022.
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

int is_good_node(TreeNode* node, int max_val) {
    if (!node) return 0;

    auto good_node_count = 0;
    max_val = std::max(max_val, node->val);
    if (max_val == node->val) good_node_count++;

    good_node_count += is_good_node(node->left, max_val) + is_good_node(node->right, max_val);
    return good_node_count;
}

int goodNodes(TreeNode* root) {
    return is_good_node(root, std::numeric_limits<int>::min());
}