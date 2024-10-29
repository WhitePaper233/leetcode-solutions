/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int j = len - 1, i = len - 2, k = len - 1;
        while (i >= 0 && nums[i] >= nums[j]) {
            --i; --j;
        }

        if (i >= 0) {
            while (nums[i] >= nums[k]) {
                --k;
            }
            swap(nums[i], nums[k]);
        }

        i = j; j = len - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            ++i; --j;
        }
    }
};
// @lc code=end

