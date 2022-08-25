//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
    // Write your code here.
    int prefix = 1, suffix = 1;
    vector<int> products(array.size(), 1);

    for (auto i = 1; i < array.size(); i++) {
        prefix *= array[i - 1];
        products[i] *= prefix;
    }

    for (int i = array.size() - 2; i >= 0; i--) {
        suffix *= array[i + 1];
        products[i] *= suffix;
    }

    return products;
}
