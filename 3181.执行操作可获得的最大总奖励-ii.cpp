/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 *
 * [3181] 执行操作可获得的最大总奖励 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();

        sort(rewardValues.begin(), rewardValues.end());
        
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return 2 * rewardValues[n - 1] - 1;
        }

        bitset<100000> dp0 ,dp1;
        dp0[0] = 1;

        for (int i = 0, j = 0; i < n; ++i) {
            int v = rewardValues[i];

            for (; j < v; ++j) {
                dp1[j] = dp0[j];
            }

            dp0 = dp0 | (dp1 << v);
        }

        int maxVal = 0;
        for (int i = 0; i < dp0.size(); ++i) {
            if (dp0[i]) maxVal = i;
        }

        return maxVal;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<int> d = {1,1,3,3};
    auto x = sol.maxTotalReward(d);

    return 0;
}
