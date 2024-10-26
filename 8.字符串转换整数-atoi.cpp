/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false, startRead = false;
        int64 number = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (startRead && (s[i] < '0' || s[i] > '9')) break;
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-') {
                startRead = true;
                isNegative = s[i] == '-' ? true : false;
                continue;
            }
            if (s[i] < '0' || s[i] > '9') break;
            startRead = true;
            number *= 10;
            number += s[i] - '0';
            if ((isNegative ? -number : number) > INT32_MAX) {
                return INT32_MAX;
            }
            if ((isNegative ? -number : number) < INT32_MIN) {
                return INT32_MIN;
            }
        }
        return isNegative ? static_cast<int>(-number) : static_cast<int>(number);
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    sol.myAtoi("-91283472332");

    return 0;
}
