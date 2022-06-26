//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    std::unordered_set<int> visited;
    std::unordered_map<int, Node*> cloned;
    Node* head = new Node(node->val, node->neighbors);
    cloned.insert({head->val, head});

    std::queue<Node*> queue;
    queue.push(head);

    while (!queue.empty()) {
        auto front = queue.front();
        visited.emplace(front->val);

        for (auto i = 0; i < front->neighbors.size(); i++) {
            auto neighbor = front->neighbors[i];
            auto cloned_it = cloned.find(neighbor->val);
            if (cloned_it != cloned.end()) {
                front->neighbors[i] = cloned_it->second;
            } else {
                front->neighbors[i] = new Node(neighbor->val, neighbor->neighbors);
                cloned.insert({front->neighbors[i]->val, front->neighbors[i]});
            }

            if (visited.count(front->neighbors[i]->val)) continue;
            queue.push(front->neighbors[i]);
        }
        queue.pop();
    }

    return head;
}