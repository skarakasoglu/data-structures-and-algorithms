//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
    // Write your code here.

    auto n = array.size();

    for (auto i = 0; i < n; i++) {
        auto min_idx = i;

        for (auto j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i)
            std::swap(array[i], array[min_idx]);
    }

    return array;
}
