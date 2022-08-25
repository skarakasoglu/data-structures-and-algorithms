//
// Created by Süleyman Karakaşoğlu on 19.08.2022.
//

#include <vector>

std::vector<int> sortedSquaredArray(std::vector<int> array) {
    std::vector<int> res(array.size());

    int current_pos = array.size() - 1;
    int left_pointer = 0, right_pointer = array.size() - 1;
    while (left_pointer <= right_pointer) {
        if (std::abs(array[left_pointer]) > std::abs(array[right_pointer])) {
            res[current_pos] = array[left_pointer] * array[left_pointer];
            left_pointer++;
        } else {
            res[current_pos] = array[right_pointer] * array[right_pointer];
            right_pointer--;
        }
        current_pos--;
    }

    return res;
}