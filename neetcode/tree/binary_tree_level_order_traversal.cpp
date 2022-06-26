//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <queue>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    std::vector<std::vector<int>> res;

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int n = queue.size();

        std::vector<int> level;
        for (auto i = 0; i < n; i++) {
            auto front = queue.front();
            if (front) {
                level.emplace_back(front->val);

                queue.push(front->left);
                queue.push(front->right);
            }

            queue.pop();
        }

        if (!level.empty())
            res.emplace_back(level);

    }

    return res;
}