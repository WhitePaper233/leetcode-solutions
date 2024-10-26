/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest { };
        for (int m = 0; m < s.size(); ++m) {
            for (int i = 0; m - i > -1 && m + i < s.size(); ++i) {
                if (s[m - i] != s[m + i]) break;
                if (longest.size() < 2 * i + 1) {
                    longest = s.substr(m - i, i * 2 + 1);
                }
            }
        }
        for (int m = 1; m < s.size(); ++m) {
            for (int i = 0; m - i > 0 && m + i < s.size(); ++i) {
                if (s[m - i - 1] != s[m + i]) break;
                if (longest.size() < 2 * i + 2) {
                    longest = s.substr(m - i - 1, i * 2 + 2);
                }
            }
        }
        return longest;
    }
};
// @lc code=end

