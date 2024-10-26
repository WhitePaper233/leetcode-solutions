/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLowerBound(nums, target), searchUpperBound(nums, target)};
    }

    int searchLowerBound(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (nums[m] >= target) j = m - 1;
            else i = m + 1;
        }
        
        if (i >= nums.size() || nums[i] != target) return -1;
        return i;
    }

    int searchUpperBound(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (nums[m] <= target) i = m + 1;
            else j = m - 1;
        }

        if (i - 1 >= nums.size() || nums[i - 1] != target) return -1;
        return i - 1;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<int> nums = {-99999,-99998,-9999,-999,-99,-9,-1};
    auto a = sol.searchRange(nums, 0);

    return 0;
}
