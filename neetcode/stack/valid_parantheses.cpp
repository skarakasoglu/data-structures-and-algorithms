//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <string>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::unordered_map<char, char> input_map({
         {'(', ')'},
         {'{', '}'},
         {'[', ']'},
    });
    std::stack<char> paranthese_stack;
    
    for (auto ch: s) {
        auto input_it = input_map.find(ch);
        if (input_it != input_map.end()) {
            paranthese_stack.push(ch);
            continue;
        }

        if (paranthese_stack.empty()) return false;
        auto top = paranthese_stack.top();
        auto closing_bracket_it = input_map.find(top);
        if (closing_bracket_it == input_map.end()) {
            return false;
        }

        if (closing_bracket_it->second != ch) {
            return false;
        }

        paranthese_stack.pop();
    }

    return paranthese_stack.empty();
}