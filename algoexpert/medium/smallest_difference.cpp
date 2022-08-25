//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    // Write your code here.
    std::sort(arrayOne.begin(), arrayOne.end());
    std::sort(arrayTwo.begin(), arrayTwo.end());

    int first_arr = 0, second_arr = 0;
    int min_diff = std::numeric_limits<int>::max();
    vector<int> min_diff_vals;

    while (first_arr < arrayOne.size() && second_arr < arrayTwo.size()) {
        int diff = std::abs(arrayOne[first_arr] - arrayTwo[second_arr]);
        if (diff > min_diff) {
        } else {
            min_diff = diff;
            min_diff_vals = {arrayOne[first_arr], arrayTwo[second_arr]};
        }
        if (arrayOne[first_arr] < arrayTwo[second_arr]) first_arr++;
        else second_arr++;
    }

    return min_diff_vals;
}
