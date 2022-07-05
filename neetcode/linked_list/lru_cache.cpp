//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <unordered_map>

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, Node*> cache;
    Node* most_recent{nullptr};
    Node* least_recent{nullptr};
    int capacity{0};

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        auto prev = most_recent->prev;
        auto next = most_recent;
        prev->next = node;
        next->prev = node;
        node->next = next;
        node->prev = prev;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        most_recent = new Node(0, 0);
        least_recent = new Node(0, 0);
        most_recent->prev = least_recent;
        least_recent->next = most_recent;
    }

    int get(int key) {
        if (cache.count(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }

        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > capacity) {
            auto lru = least_recent->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};