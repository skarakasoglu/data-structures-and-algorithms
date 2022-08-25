//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
#include <string>
#include <unordered_map>

using namespace std;

bool generateDocument(string characters, string document) {
    // Write your code here.
    std::unordered_map<char, int> char_occurrences;
    std::unordered_map<char, int> doc_occurrences;

    for (auto i = 0; i < characters.size(); i++) {
        char_occurrences[characters[i]]++;
    }

    for (auto i = 0; i < document.size(); i++) {
        auto char_it = char_occurrences.find(document[i]);
        if (char_it == char_occurrences.end()) {
            return false;
        }

        auto doc_it = doc_occurrences.insert({document[i], 1});
        if (!doc_it.second) {
            doc_it.first->second++;
        }

        if (doc_it.first->second > char_it->second) {
            return false;
        }

    }

    return true;
}
