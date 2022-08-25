//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//

#include <vector>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
    // Write your code here.
    std::sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    std::sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());

    int n = redShirtSpeeds.size();
    int possible_total_speed = 0;

    int left = 0, right = n - 1;
    while (left <= right) {
        if (fastest) {
            auto speed = std::max(redShirtSpeeds[right], blueShirtSpeeds[left]);
            possible_total_speed += speed;

            if (left != right) {
                speed = std::max(redShirtSpeeds[left], blueShirtSpeeds[right]);
                possible_total_speed += speed;
            }
        } else {
            auto speed = std::max(redShirtSpeeds[right], blueShirtSpeeds[right]);
            possible_total_speed += speed;

            if (left != right) {
                speed = std::max(redShirtSpeeds[left], blueShirtSpeeds[left]);
                possible_total_speed += speed;
            }
        }
        left++;
        right--;
    }

    // blue: 1, 2, 3, 6, 7
    // red:  2, 3, 5, 5, 9
    return possible_total_speed;
}
