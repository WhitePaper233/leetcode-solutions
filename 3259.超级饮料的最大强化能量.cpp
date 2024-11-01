/*
 * @lc app=leetcode.cn id=3259 lang=cpp
 *
 * [3259] 超级饮料的最大强化能量
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        vector<int64> dp1(energyDrinkA.size()), dp2(energyDrinkB.size());

        dp1[0] = energyDrinkA[0]; dp1[1] = dp1[0] + energyDrinkA[1];
        dp2[0] = energyDrinkB[0]; dp2[1] = dp2[0] + energyDrinkB[1];

        for (int i = 2; i < dp1.size(); ++i) {
            dp1[i] = max(
                energyDrinkA[i] + dp1[i - 1],
                energyDrinkA[i] + dp2[i - 2]
            );
            dp2[i] = max(
                energyDrinkB[i] + dp2[i - 1],
                energyDrinkB[i] + dp1[i - 2]
            );
        }

        return max(dp1[dp1.size() - 1], dp2[dp2.size() - 1]);
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<int> a = {4,1,1}, b = {1,1,3};
    sol.maxEnergyBoost(a, b);

    return 0;
}
