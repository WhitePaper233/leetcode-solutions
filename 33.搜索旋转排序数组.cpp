/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return _search(nums, 0, nums.size() - 1, target);
    }

    int _search(vector<int>& nums, int first, int last, int target) {
        if (last - first <= 2) {
            for (int i = first; i <= last; ++i) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        int i = first, j = last, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (nums[first] < nums[m]) {
                if (nums[first] <= target && nums[m] >= target) {
                    return binarySearch(nums, first, m, target);
                } else {
                    return _search(nums, m, last, target);
                }
            } else if (nums[last] > nums[m]) {
                if (nums[last] >= target && nums[m] <= target) {
                    return binarySearch(nums, m, last, target);
                } else {
                    return _search(nums, first, m, target);
                }
            } else return m;
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int first, int last, int target) {
        int i = first, j = last, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (nums[m] < target) i = m + 1;
            else if (nums[m] > target) j = m - 1;
            else return m;
        }
        return -1;
    }
};
// @lc code=end
