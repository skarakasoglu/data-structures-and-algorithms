//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
    // Write your code here.

    auto n = array.size();
    for (auto i = 0; i < n - 1; i++) {

        bool isSwapped = false;
        for (auto j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped) break;
    }
    return array;
}
