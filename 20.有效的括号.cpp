/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack {};
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (char ch : s) {
            if (mapping.count(ch)) {
                if (!bracketStack.empty() && bracketStack.top() == mapping[ch]) {
                    bracketStack.pop();
                    continue;
                }
                return false;
            }
            bracketStack.push(ch);
        }

        return bracketStack.empty() ? true : false;
    }
};
// @lc code=end

