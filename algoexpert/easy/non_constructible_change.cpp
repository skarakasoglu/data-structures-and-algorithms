//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    std::sort(coins.begin(), coins.end());

    int target = 0;
    for (auto i = 0; i < coins.size(); i++) {
        if (coins[i] > target + 1) {
            return target + 1;
        } else {
            target += coins[i];
        }
    }

    return target + 1;
}