//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>
#include <cmath>

int minEatingSpeed(std::vector<int>& piles, int h) {
    int max = 0;
    for (auto i = 0; i < piles.size(); i++) {
        if (piles[i] > max) max = piles[i];
    }

    auto can_eat = [&h, &piles](int eating_speed) -> bool {
        int hours = 0;
        for (auto i = 0; i < piles.size(); i++) {
            hours += std::ceil(piles[i] / (double)eating_speed);
            if (hours > h) return false;
        }

        return true;
    };

    int left = 1, right = max;
    int boundary = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (can_eat(mid)) {
            boundary = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return boundary;
}