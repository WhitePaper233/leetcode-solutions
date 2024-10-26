/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int i : nums) sum -= i;
        return sum;
    }
};
// @lc code=end
