//
// Created by Süleyman Karakaşoğlu on 6.07.2022.
//
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> nodes;
    auto n = 0;
    auto current = root;

    while (current || !nodes.empty()) {
        while (current) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        n++;
        if (n == k) {
            return current->val;
        }
        current = current->right;
        nodes.pop();
    }

    return -1;
}