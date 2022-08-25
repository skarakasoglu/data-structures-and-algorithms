//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

bool isMonotonic(vector<int> array) {
    // Write your code here.

    bool increasing = false, decreasing= false;
    for (auto i = 1; i < array.size(); i++) {
        if (array[i] == array[i - 1]) continue;

        if (array[i] > array[i - 1]) {
            if (decreasing) return false;
            increasing = true;
        }

        if (array[i] < array[i - 1]) {
            if (increasing) return false;
            decreasing = true;
        }
    }
    return true;
}
