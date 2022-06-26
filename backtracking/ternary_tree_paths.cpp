//
// Created by Süleyman Karakaşoğlu on 16.06.2022.
//

#include <vector>
#include <map>
#include <iostream>
#include <string>

template <typename T>
struct Node {
    T val;
    std::vector<Node<T>*> children;

    explicit Node(T val, std::vector<Node<T>*> children = {})
            : val{val}, children{children} {}
};

void dfs(Node<int>* root, std::vector<std::string>& paths, std::string& path) {
    if (root->children.empty()) {
        path += std::to_string(root->val);
        paths.push_back(path);
        return;
    }

    for (auto i = 0; i < 3; i++) {
        auto child = root->children[i];

        if (child) {
            auto child_path = path + std::to_string(root->val) + "->";
            dfs(child, paths, child_path);
        }
    }
}

std::vector<std::string> ternary_tree_paths(Node<int>* root) {
    std::vector<std::string> paths;
    std::string path;
    dfs(root, paths, path);
    return paths;
}

void dfs(std::vector<char> path, bool used[], std::vector<std::string>& res, std::string letters) {
    if (path.size() == letters.size()) {
        std::string s(path.begin(), path.end());
        res.emplace_back(s);
        return;
    }

    for (auto i = 0; i < letters.size(); i++) {
        if (used[i]) continue;

        path.emplace_back(letters[i]);
        used[i] = true;
        dfs(path, used, res, letters);
        path.pop_back();
        used[i] = false;
    }
}

std::vector<std::string> permutations(std::string letters) {
    std::vector<std::string> res;
    bool used[letters.size()];
    dfs({}, used, res, letters);

    return res;
}
std::map<char, std::string> keyboard{
        { '2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
};

void phone_number_dfs(std::vector<char> comb, std::vector<std::string>& res, std::string digits, int i) {
    if (comb.size() == digits.size()) {
        std::string s(comb.begin(), comb.end());
        res.emplace_back(s);
        return;
    }

    for (char& c: keyboard[digits[i]]) {
        comb.emplace_back(c);
        phone_number_dfs(comb, res, digits, i + 1);
        comb.pop_back();
    }
}

std::vector<std::string> letter_combinations_of_phone_number(std::string digits) {
    std::vector<std::string> res;

    phone_number_dfs({}, res, digits, 0);
    return res;
}