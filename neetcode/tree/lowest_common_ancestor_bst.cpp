//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto cur = root;

    while (cur) {
        if (p->val > cur->val && q->val > cur->val) {
            cur = cur->right;
        } else if (p->val < cur->val && q->val < cur->val) {
            cur = cur->left;
        } else {
            return cur;
        }
    }

    return nullptr;
}