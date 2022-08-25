//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    // Write your code here.
    vector<vector<int>> res;

    std::sort(array.begin(), array.end());
    for (auto i = 0; i < array.size(); i++) {
        if (i > 0 && array[i] == array[i - 1]) continue;
        auto currentTarget = targetSum - array[i];

        int left = i + 1, right = array.size() - 1;
        while (left < right) {
            if (array[left] + array[right] > currentTarget) right--;
            else if (array[left] + array[right] < currentTarget) left++;
            else {
                res.push_back({array[i], array[left], array[right]});
                left++;
            }
        }
    }

    return res;
}
