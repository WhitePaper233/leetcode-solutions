/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int strIndex = 1; strIndex < strs.size(); ++strIndex) {
            if (prefix.empty()) return prefix;
            int i = 0;
            while (i < prefix.size() && i < strs[strIndex].size()) {
                if (prefix[i] != strs[strIndex][i]) break;
                ++i;
            }
            prefix = prefix.substr(0, i);
        }
        return prefix;
    }
};
// @lc code=end
