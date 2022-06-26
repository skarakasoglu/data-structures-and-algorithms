//
// Created by Süleyman Karakaşoğlu on 23.06.2022.
//

#include <vector>

void move_zeros(std::vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            int slow_num = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = slow_num;
            slow++;
        }
    }
}