//
// Created by Süleyman Karakaşoğlu on 23.06.2022.
//

#include <vector>

std::vector<int> two_sum_sorted(std::vector<int> arr, int target) {
    int i = 0, j = arr.size() - 1;

    while (i < j) {
        auto sum = arr[i] + arr[j];
        if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        } else {
            return {i, j};
        }
    }

    return {};
}