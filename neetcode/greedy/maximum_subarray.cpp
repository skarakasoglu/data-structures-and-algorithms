//
// Created by Süleyman Karakaşoğlu on 25.06.2022.
//

#include <vector>

int maxSubArray(std::vector<int>& nums) {
    auto maxSub = nums[0];
    int curSum = 0;

    for (const auto& n: nums) {
        if (curSum < 0) {
            curSum = 0;
        }

        curSum += n;
        maxSub = std::max(maxSub, curSum);
    }

    return maxSub;
}