//
// Created by Süleyman Karakaşoğlu on 16.06.2022.
//

#include <vector>
#include <sstream>
#include <string>

template <typename T>
struct Node{
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr) : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

int tree_max_depth(Node<int>* root) {
    if (root == nullptr) return 0;

    auto left_depth = tree_max_depth(root->left);
    auto right_depth = tree_max_depth(root->right);

    return std::max(left_depth, right_depth) + 1;
}

int dfs_visible(Node<int>* root, int max) {
    bool is_visible = false;

    if (root == nullptr) return 0;
    if (root->val >= max) {
        is_visible = true;
        max = root->val;
    }

    int left_visible_count = dfs_visible(root->left, max);
    int right_visible_count = dfs_visible(root->right, max);
    int total_visible_count = left_visible_count + right_visible_count;

    return is_visible ? total_visible_count + 1 : total_visible_count;
}

int visible_tree_node(Node<int>* root) {
    return dfs_visible(root, std::numeric_limits<int>::min());
}

bool dfs_balanced(Node<int>* root, int& height) {
    if (root == nullptr) { return true; }

    int left_height = 0, right_height = 0;
    bool left_balanced = dfs_balanced(root->left, left_height);
    bool right_balanced = dfs_balanced(root->right, right_height);

    int max_height = std::max(left_height, right_height);
    height = max_height + 1;

    return left_balanced && right_balanced && std::abs(left_height - right_height) <= 1;
}

bool is_balanced(Node<int>* root) {
    int height = 0;
    return dfs_balanced(root, height);
}


void serialize_dfs(Node<int>* root, std::vector<std::string>& res) {
    if (root == nullptr) {
        res.emplace_back("x");
        return;
    }
    res.emplace_back(std::to_string(root->val));
    serialize_dfs(root->left, res);
    serialize_dfs(root->right, res);
}

std::string serialize(Node<int>* root) {
    std::vector<std::string> res;
    serialize_dfs(root, res);
    std::stringstream ss;
    std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(ss, " "));
    return ss.str();
}

Node<int>* deserialize_dfs(std::vector<std::string>::iterator& nodes) {
    std::string val = *nodes;
    ++nodes;
    if (val == "x") return nullptr;
    Node<int>* cur = new Node<int>(std::stoi(val));
    cur->left = deserialize_dfs(nodes);
    cur->right = deserialize_dfs(nodes);
    return cur;
}

Node<int>* deserialize(std::string root) {
    std::istringstream ss(root);
    std::vector<std::string> nodes;
    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::back_inserter(nodes));
    auto nodes_iter = nodes.begin();

    return deserialize_dfs(nodes_iter);
}

Node<int>* lca(Node<int>* root, Node<int>* node1, Node<int>* node2) {
    if (root == nullptr) return nullptr;

    if (root == node1 || root == node2) return root;

    auto left_ancestor = lca(root->left, node1, node2);
    auto right_ancestor = lca(root->right, node1, node2);

    if (left_ancestor && right_ancestor) return root;

    if (left_ancestor) return left_ancestor;
    if (right_ancestor) return right_ancestor;

    return nullptr;
}