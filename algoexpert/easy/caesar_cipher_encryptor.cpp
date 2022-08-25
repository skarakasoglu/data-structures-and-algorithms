//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//

#include <sstream>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
    // Write your code here.

    std::stringstream ss;
    key = key % ('z' - 'a' + 1);
    for (auto i = 0; i < str.size(); i++) {
        char encrypted_char;
        if (str[i] + key > 'z') {
            encrypted_char = 'a' + (str[i] + key - 'z' - 1);
        } else {
            encrypted_char = str[i] + key;
        }

        ss << encrypted_char;
    }

    return ss.str();
}
