//
// Created by Süleyman Karakaşoğlu on 23.06.2022.
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

int mst_forest(int trees, std::vector<std::vector<int>> pairs) {
    std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] < b[2];
    });

    disjoint_set my_set;

    int ret = 0;
    int count = 0;
    for (const auto& pair: pairs) {

        auto edgeA = pair[0];
        auto edgeB = pair[1];
        auto weight = pair[2];
        if (my_set.find(edgeA) != my_set.find(edgeB)) {
            my_set.unionVals(edgeA, edgeB);
            count++;
            ret += weight;
        }
    }

    return ret;
}