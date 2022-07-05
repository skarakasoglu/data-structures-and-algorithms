//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};

    std::queue<TreeNode*> node_queue;
    node_queue.push(root);

    std::vector<int> res;
    while (!node_queue.empty()) {
        auto n = node_queue.size();
        for (auto i = 0; i < n; i++) {
            auto front = node_queue.front();
            if (i == 0) res.emplace_back(front->val);

            if (front->right) node_queue.push(front->right);
            if (front->left) node_queue.push(front->left);

            node_queue.pop();
        }
    }

    return res;
}