//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
    // Write your code here.

    auto n = array.size();
    for (auto i = 1; i < n; i++) {
        auto key = array[i];
        auto j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
    return array;
}
