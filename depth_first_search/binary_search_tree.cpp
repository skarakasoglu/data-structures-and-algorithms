//
// Created by Süleyman Karakaşoğlu on 16.06.2022.
//

#include "depth_first_search.cpp"

bool validate_bst(Node<int>* root, int max, int min) {
    if (!root) return true;
    if (root->val > max || root->val < min) return false;

    auto left_valid = validate_bst(root->left, root->val, min);
    auto right_valid = validate_bst(root->right, max, root->val);

    return left_valid && right_valid;
}

bool valid_bst(Node<int>* root) {
    return validate_bst(root, std::numeric_limits<int>::max(), std::numeric_limits<int>::min());
}

Node<int>* insert_bst(Node<int>* bst, int val) {
    if (!bst) {
        bst = new Node<int>(val, nullptr, nullptr);
        return bst;
    }

    if (bst->val < val) {
        bst->right = insert_bst(bst->right, val);
    }
    if (bst->val > val) {
        bst->left = insert_bst(bst->left, val);
    }

    return bst;
}

Node<int>* invert_binary_tree(Node<int>* tree) {
    if (!tree) return nullptr;

    auto inverted_left_subtree = invert_binary_tree(tree->left);
    auto inverted_right_subtree = invert_binary_tree(tree->right);

    tree->left = inverted_right_subtree;
    tree->right = inverted_left_subtree;

    return tree;
}