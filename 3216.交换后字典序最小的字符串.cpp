/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 *
 * [3216] 交换后字典序最小的字符串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

#define toDigit(ch) (ch - '0')

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] > s[i] && toDigit(s[i]) % 2 == toDigit(s[i - 1]) % 2) {
                swap(s[i], s[i - 1]);
                break;
            }
        }
        return s;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    sol.getSmallestString("10");

    return 0;
}