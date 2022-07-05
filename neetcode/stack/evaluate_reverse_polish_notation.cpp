//
// Created by Süleyman Karakaşoğlu on 5.07.2022.
//

#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

int evalRPN(std::vector<std::string>& tokens) {

    std::stack<int> number_stack;
    std::unordered_map<std::string, std::function<int(const int&, const int&)>> operands{
            {"+", [](const int& a, const int& b) {return a + b; } },
            {"-", [](const int& a, const int& b) {return a - b; } },
            {"/", [](const int& a, const int& b) {return a / b; } },
            {"*", [](const int& a, const int& b) {return a * b; } }
    };

    auto result = 0;
    for (auto i = 0; i < tokens.size(); i++) {
        auto current_token = tokens[i];

        auto operand_it = operands.find(current_token);
        if (operand_it != operands.end()) {
            auto first_num = number_stack.top();
            number_stack.pop();

            auto second_num = number_stack.top();
            number_stack.pop();

            result = operand_it->second(second_num, first_num);
            number_stack.push(result);
            continue;
        }

        number_stack.push(std::stoi(current_token));
    }

    return number_stack.top();
}