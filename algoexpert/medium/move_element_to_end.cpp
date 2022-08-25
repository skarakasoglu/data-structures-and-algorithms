//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    int n = array.size();
    int count = 0;

    for (auto i = 0; i < n - count; i++) {
        if (array[i] == toMove) {
            std::swap(array[i], array[n - 1 - count]);
            count++;
            i--;
        }
    }

    return array;
}
