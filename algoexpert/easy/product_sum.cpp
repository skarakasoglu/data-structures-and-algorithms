//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <any>
#include <vector>

using namespace std;

int productSum(int depth, vector<any> array) {
    int sum = 0;
    for (auto& elem: array) {
        if (elem.type() == typeid(vector<any>)) {
            sum += (depth + 1) * productSum(depth + 1, any_cast<vector<any>>(elem));
        } else {
            sum += any_cast<int>(elem);
        }
    }

    return sum;
}

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array) {
    return productSum(1, array);
}

