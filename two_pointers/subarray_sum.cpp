//
// Created by Süleyman Karakaşoğlu on 24.06.2022.
//

#include <vector>
#include <unordered_map>

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    std::unordered_map<int, int> prefix_sums;

    prefix_sums[0] = 0;
    int cur_sum = 0;
    for (auto i = 0; i < arr.size(); i++) {
        cur_sum += arr[i];
        int complement = cur_sum - target;
        if (prefix_sums.count(complement)) {
            return {prefix_sums[complement], i + 1};
        }

        prefix_sums[cur_sum] = i  + 1;
    }

    return {};
}
int subarray_sum_total(std::vector<int> arr, int target) {
    std::unordered_map<int, int> prefix_sums;
    prefix_sums[0] = 1;  // an empty array has a sum of 0
    int cur_sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++) {
        cur_sum += arr[i];
        int complement = cur_sum - target;
        if (prefix_sums.count(complement)) {
            count += prefix_sums[complement];
        }
        if (prefix_sums.count(cur_sum)) {
            prefix_sums[cur_sum] += 1;
        } else {
            prefix_sums[cur_sum] = 1;
        }
    }
    return count;
}