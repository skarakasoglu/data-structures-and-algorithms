//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products(nums.size(), 1);

    auto prefix = 1;
    auto suffix = 1;

    for (auto i = 1; i < nums.size(); i++) {
        prefix *= nums[i - 1];
        products[i] *= prefix;
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        products[i] *= suffix;
    }

    return products;
}