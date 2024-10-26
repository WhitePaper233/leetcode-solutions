/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

using int64 = int64_t;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        int m;
        while (i <= j) {
            m = i + (j - i) / 2;

            if (nums[m] < target) {
                i = m + 1;
            } else if (nums[m] > target) {
                j = m - 1;
            } else {
                return m;
            }
        }
        
        if (target > nums[m]) return m + 1;
        return m;
    }
};
// @lc code=end

int main() {
    auto sol = Solution{};
    vector<int> nums = {1,3,5,6};
    sol.searchInsert(nums, 2);
}
