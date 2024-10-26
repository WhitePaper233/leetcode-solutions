/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int begin, int end) {
        if (end - begin < 4) {
            int min = INT32_MAX;
            for (int i = begin; i <= end; ++i) {
                if (nums[i] < min) min = nums[i];
            }
            return min;
        }
        
        int m = begin + (end - begin) / 2;
        int prev = nums[m - 1], next = nums[m], left_min, right_min;

        if (prev > nums[begin]) {
            left_min = nums[begin];
        } else {
            left_min = search(nums, begin, m - 1);
        }

        if (next < nums[end]) {
            right_min = next;
        } else {
            right_min = search(nums, m, end);
        }

        return min(left_min, right_min);
    }
};
// @lc code=end
