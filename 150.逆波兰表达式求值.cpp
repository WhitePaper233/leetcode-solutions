/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stk {};
        for (auto token : tokens) {
            if (is_op(token)) {
                int b = num_stk.top(); num_stk.pop();
                int a = num_stk.top(); num_stk.pop();
                num_stk.push(calc(a, b, token[0]));
                continue;
            }
            num_stk.push(stoi(token));
        }
        return num_stk.top();
    }

    int calc(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }

    bool is_op(string token) {
        return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
    }
};
// @lc code=end

