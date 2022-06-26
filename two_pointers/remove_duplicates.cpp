//
// Created by Süleyman Karakaşoğlu on 23.06.2022.
//

#include <vector>

int remove_duplicates(std::vector<int>& arr) {
    int i = 0, j = 0;
    while (j < arr.size()) {
        if (arr[i] != arr[j]) {
            arr[i + 1] = arr[j];
            i++;
        }
        j++;
    }

    return i + 1;
}