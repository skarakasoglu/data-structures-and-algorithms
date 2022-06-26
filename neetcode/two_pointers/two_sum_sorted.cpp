//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            return {left, right};
        }
    }

    return {};
}