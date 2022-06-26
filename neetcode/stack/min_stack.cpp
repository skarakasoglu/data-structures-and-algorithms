//
// Created by Süleyman Karakaşoğlu on 21.06.2022.
//

#include <stack>

class MinStack{
private:
    std::stack<int> stack;
    std::stack<int> min_stack;
public:
    MinStack() {

    }

    void push(int val) {
        stack.push(val);

        if (min_stack.empty())  {
            min_stack.push(val);
            return;
        }

        auto min_val = min_stack.top();
        if (val <= min_val) {
            min_stack.push(val);
        }
    }

    void pop() {
        int top = stack.top();
        int min_top = min_stack.top();

        if (top == min_top) {
            min_stack.pop();
        }

        stack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        if (min_stack.empty()) return 0;

        return min_stack.top();
    }
};