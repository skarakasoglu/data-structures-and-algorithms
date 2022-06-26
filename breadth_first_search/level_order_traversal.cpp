//
// Created by Süleyman Karakaşoğlu on 18.06.2022.
//

#include <vector>
#include <queue>

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
            : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

std::vector<std::vector<int>> level_order_traversal(Node<int>* root) {
    std::queue<Node<int>*> q;
    q.push(root);

    std::vector<std::vector<int>> res;
    std::vector<int> cur;

    int n = 1;

    while (n > 0) {
        int next_children_count = 0;

        for (auto i = 0; i < n; i++) {
            auto current = q.front();

            if (current->left) {
                q.push(current->left);
                next_children_count++;
            }

            if (current->right) {
                q.push(current->right);
                next_children_count++;
            }

            cur.emplace_back(current->val);
            q.pop();
        }

        n = next_children_count;
        res.emplace_back(cur);
        cur.clear();
    }

    return res;
}

std::vector<std::vector<int>> zig_zag_traversal(Node<int>* root) {
    std::queue<Node<int>*> q;

    std::vector<std::vector<int>> res;
    q.push(root);

    int current_level_num = 0;
    while (q.size() > 0) {
        int n = q.size();
        std::vector<int> current_level(n);

        for (auto i = 0; i < n; i++) {
            auto current = q.front();

            if (current_level_num % 2 == 1) {
                current_level[n - i - 1] = current->val;
            } else {
                current_level[i] = current->val;
            }

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);

            q.pop();
        }

        current_level_num++;
        res.emplace_back(current_level);
    }

    return res;
}

std::vector<int> binary_tree_right_side_view(Node<int>* root) {
    std::vector<int> res;

    std::queue<Node<int>*> queue;
    queue.push(root);

    while (queue.size() > 0) {
        int n = queue.size();

        res.emplace_back(queue.front()->val);
        for (auto i = 0; i < n; i++) {
            auto current = queue.front();

            if (current->right) queue.push(current->right);
            if (current->left) queue.push(current->left);

            queue.pop();
        }
    }

    return res;
}

int binary_tree_min_depth(Node<int>* root) {
    std::queue<Node<int>*> queue;
    queue.push(root);

    int min_depth = 0;
    while(queue.size() > 0) {
        int n = queue.size();

        for (auto i = 0; i < n; i++) {
            auto current = queue.front();

            if (!current->left && !current->right) {
                return min_depth;
            }

            if (current->left) queue.push(current->left);
            if (current->right) queue.push(current->right);

            queue.pop();
        }

        min_depth++;
    }

    return min_depth;
}