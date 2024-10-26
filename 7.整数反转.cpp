/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int reverse(int x) {
        string num = to_string(x), reversed { };
        bool isNegative = x < 0;

        if (isNegative) num = num.substr(1, num.size() - 1);
        for (int i = num.size() - 1; i > -1; --i) {
            reversed.push_back(num[i]);
        }
        if (isNegative) reversed.insert(reversed.begin(), '-');

        string compareNum = isNegative ? to_string(INT32_MIN) : to_string(INT32_MAX);
        if (reversed.size() < compareNum.size() || compareNum == reversed) {
            return atoi(reversed.c_str());
        }
        if (reversed.size() > compareNum.size()) {
            return 0;
        }

        int reversedHead = atoi(reversed.substr(0, reversed.size() - 1).c_str());
        int compareHead = atoi(compareNum.substr(0, compareNum.size() - 1).c_str());
        if (abs(reversedHead) > abs(compareHead)) {
            return 0;
        }
        if (reversed[reversed.size() - 1] > compareNum[compareNum.size() - 1]) {
            return 0;
        }
        
        return atoi(reversed.c_str());
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    sol.reverse(1534236469);

    return 0;
}
