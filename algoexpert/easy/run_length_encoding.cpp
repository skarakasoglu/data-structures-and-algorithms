//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <sstream>

using namespace std;


string runLengthEncoding(string str) {
    // Write your code here.
    std::stringstream run_length_encoded_ss;

    int letter_counter = 1;
    char prev_char = str[0];
    for (auto i = 1; i <= str.size(); i++) {
        if (i < str.size() && prev_char == str[i] && letter_counter < 9) {
            letter_counter++;
        } else {
            run_length_encoded_ss << letter_counter << prev_char;
            letter_counter = 1;
            prev_char = str[i];
        }
    }

    return run_length_encoded_ss.str();
}
