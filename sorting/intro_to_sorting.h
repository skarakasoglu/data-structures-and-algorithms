//
// Created by Süleyman Karakaşoğlu on 16.06.2022.
//
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_INTRO_TO_SORTING_H
#define DATA_STRUCTURES_AND_ALGORITHMS_INTRO_TO_SORTING_H


std::vector<int> merge_sort(std::vector<int> unsorted_list) {
    int n = unsorted_list.size();
    if (n <= 1) {
        return unsorted_list;
    }


    auto mid = n / 2;
    auto left_list = merge_sort(std::vector<int>(unsorted_list.begin(), unsorted_list.begin() + mid));
    auto right_list = merge_sort(std::vector<int>(unsorted_list.begin() + mid, unsorted_list.end()));

    std::vector<int> res;
    int left = 0, right = 0;
    while (left < mid || right < n - mid) {
        if (left == mid) {
            res.push_back(right_list[right]);
            right++;
        } else if (right == n - mid) {
            res.push_back(left_list[left]);
            left++;
        } else if (left_list[left] <= right_list[right]) {
            res.push_back(left_list[left]);
            left++;
        } else {
            res.push_back(right_list[right]);
            right++;
        }
    }

    return res;
}

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    // WRITE YOUR BRILLIANT CODE HERE
    return merge_sort(unsorted_list);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

#endif //DATA_STRUCTURES_AND_ALGORITHMS_INTRO_TO_SORTING_H
