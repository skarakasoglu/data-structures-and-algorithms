//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <string>
using namespace std;

bool isPalindrome(string str) {
    // Write your code here.

    auto left_pointer = 0;
    auto right_pointer = str.size() - 1;

    while (left_pointer < right_pointer) {
        if (str[left_pointer] != str[right_pointer]) return false;

        left_pointer++;
        right_pointer--;
    }

    return true;
}
