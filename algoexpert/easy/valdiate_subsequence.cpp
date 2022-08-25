//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//

#include <vector>

bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
    // Write your code here.

    int left_pointer = 0;
    for (auto i = 0; i < array.size(); i++) {
        if (array[i] == sequence[left_pointer]) {
            left_pointer++;
            if (left_pointer == sequence.size()) return true;
        }

    }

    return false;
}

