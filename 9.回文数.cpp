/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        vector<int> nums { };
        while (x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[nums.size() - 1 - i]) return false;
        }

        return true;
    }
};
// @lc code=end

