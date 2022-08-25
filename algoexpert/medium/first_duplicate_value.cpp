//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
#include <unordered_set>
using namespace std;

int firstDuplicateValue(vector<int> array) {
    std::unordered_set<int> occurrences;

    for (int i = 0; i < array.size(); i++) {
        auto it = occurrences.insert(array[i]);
        if (!it.second) return array[i];
    }

    return -1;
}
