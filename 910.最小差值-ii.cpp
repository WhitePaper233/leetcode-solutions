/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());

        int min_diff = nums[nums.size() - 1] - nums[0];
        for (int i = 0; i < nums.size() - 1; ++i) {
            int max_val = max(nums[i] + k, nums[nums.size() - 1] - k);
            int min_val = min(nums[0] + k, nums[i + 1] - k);
            min_diff = min(min_diff, max_val - min_val);
        }

        return min_diff;
    }
};
// @lc code=end

