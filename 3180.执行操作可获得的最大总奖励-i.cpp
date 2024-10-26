/*
 * @lc app=leetcode.cn id=3180 lang=cpp
 *
 * [3180] 执行操作可获得的最大总奖励 I
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    // bf search - out of memory
    // int maxTotalReward(vector<int>& rewardValues) {
    //     vector<pair<int, bool>> markedRewardValue {};
    //     markedRewardValue.resize(rewardValues.size());
    //     for (int i = 0; i < rewardValues.size(); ++i) {
    //         markedRewardValue[i] = {rewardValues[i], false};
    //     }

    //     return solve(markedRewardValue, 0);
    // }

    // int solve(vector<pair<int, bool>> rewardValue, int x) {
    //     int maxReward = x;
    //     for (int i = 0; i < rewardValue.size(); ++i) {
    //         if (!rewardValue[i].second && rewardValue[i].first > x) {
    //             auto newRewardValue = rewardValue;
    //             newRewardValue[i].second = true;
    //             int res = solve(newRewardValue, x + rewardValue[i].first);
    //             maxReward = max(maxReward, res);
    //         }
    //     }
    //     return maxReward;
    // }

    // pack dp solution
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int cols = 2 * rewardValues[rewardValues.size() - 1];

        vector<vector<bool>> dp = vector(
            rewardValues.size() + 1, 
            vector<bool>(cols, false)
        );

        dp[0][0] = true;
        int maxVal = INT32_MIN;

        for (int i = 1; i < dp.size(); ++i) {
            int v = rewardValues[i - 1];
            for (int j = 0; j < cols; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (0 <= j - v && j - v < v) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - v];
                    if (dp[i][j]) maxVal = max(maxVal, j);
                }
            }
        }

        return maxVal;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<int> d = {1,6,4,3,2};
    auto x = sol.maxTotalReward(d);

    return 0;
}
