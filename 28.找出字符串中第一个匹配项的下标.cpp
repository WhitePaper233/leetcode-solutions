/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next {};
        CalculateNext(next, needle);

        int i = 0, j = 0;
        while (i <= haystack.size()) {
            if (j == needle.size()) {
                return i - j;
            }
            if (haystack[i] == needle[j]) {
                ++i; ++j;
                continue;
            }
            if (j == 0) {
                ++i;
                continue;
            }
            j = next[j - 1];
        }

        return -1;
    }

    void CalculateNext(vector<int>& next, string pattern) {
        next.resize(pattern.size());
        next[0] = 0;

        int i = 1, prefixLen = 0;
        while (i < pattern.size()) {
            if (pattern[i] == pattern[prefixLen]) {
                next[i] = ++prefixLen;
                ++i;
                continue;
            }
            if (prefixLen == 0) {
                next[i] = 0;
                ++i;
                continue;
            }
            prefixLen = next[prefixLen - 1];
            continue;
        }
    }
};
// @lc code=end

