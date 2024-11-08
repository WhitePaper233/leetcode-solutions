/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool start_flag = false;
        int length_count = 0;
        for (int i = s.size() - 1; i > -1; --i) {
            if (!start_flag && s[i] == ' ') continue;
            if (start_flag && s[i] == ' ') break;

            if (!start_flag) start_flag = true;
            length_count++;
        }

        return length_count;
    }
};
// @lc code=end

