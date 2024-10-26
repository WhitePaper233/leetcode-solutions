/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            int maxLength = dp[i];
            for (int j = 0; j < i; ++j) {
                if (nums[j] < v) {
                    maxLength = max(maxLength, dp[j] + 1);
                }
            }
            dp[i] = maxLength;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    vector<int> nums = {10,9,2,5,3,7,101,18};
    sol.lengthOfLIS(nums);

    return 0;
}
