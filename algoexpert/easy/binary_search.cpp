//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
    int l = 0, r = array.size() - 1;

    while (l <= r) {
        int med = (l + r) / 2;

        if (array[med] == target) return med;
        else if (array[med] < target) {
            l = med + 1;
        } else {
            r = med - 1;
        }
    }
    return -1;
}
