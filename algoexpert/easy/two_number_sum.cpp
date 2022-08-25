//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//

#include <vector>
#include <unordered_map>

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
    std::unordered_map<int, int> target_differences;

    for (auto i = 0; i < array.size() ; i++) {
        auto diff = targetSum - array[i];
        if (target_differences.count(array[i])) {
            return {array[i], array[target_differences[array[i]]]};
        }

        target_differences.insert({diff, i});
    }

    return {};
}