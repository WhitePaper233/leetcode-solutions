/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res {};

        int prev_len = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= 1) {
                if (nums[i] == nums[i - 1] + 1) prev_len++;
                else prev_len = 1;
            }
            
            if (i >= k - 1) {
                if (prev_len >= k) res.push_back(nums[i]);
                else res.push_back(-1);
            }
        }

        return res;
    }
};
// @lc code=end

