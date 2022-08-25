//
// Created by Süleyman Karakaşoğlu on 13.07.2022.
//

#include <vector>
#include <unordered_map>

class disjoint_set{
private:
    std::unordered_map<int, int> f;
public:
    int find(int x) {
        auto y_val = x;
        auto y = f.find(x);
        if (y != f.end()) {
            y_val = find(y->second);
            f.insert({x, y_val});
        }

        return y_val;
    }

    void unionVals(int x, int y) {
        f.insert({find(x), find(y)});
    }
};

int longestConsecutive(std::vector<int>& nums) {
    disjoint_set sets;

    for (auto num: nums) {
        if (sets.find())
    }

    return longest_sequence;
}