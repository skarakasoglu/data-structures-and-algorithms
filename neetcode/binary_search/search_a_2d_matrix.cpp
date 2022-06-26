//
// Created by Süleyman Karakaşoğlu on 26.06.2022.
//

#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0, bottom = rows - 1;

    int row_index = -1;
    while (top <= bottom) {
        int mid = (top + bottom) / 2;

        if (matrix[mid][0] > target) {
            bottom = mid - 1;
        } else if (matrix[mid][cols - 1] < target) {
            top = mid + 1;
        } else {
            row_index = mid;
            break;
        }
    }

    if (row_index == -1) return false;

    int left = 0, right = cols - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (matrix[row_index][mid] < target) {
            left = mid + 1;
        } else if (matrix[row_index][mid] > target) {
            right = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}