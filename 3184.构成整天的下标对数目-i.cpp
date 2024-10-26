/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 *
 * [3184] 构成整天的下标对数目 I
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> memo {};
        int cnt = 0;

        for (int i = 0; i < hours.size(); ++i) {
            int target = (24 - (hours[i] % 24)) % 24;
            if (memo.find(target) != memo.end()) {
                cnt += memo[target];
            }

            if (memo.find(hours[i] % 24) == memo.end()) {
                memo.insert({hours[i] % 24, 0});
            }

            memo[hours[i] % 24]++;
        }

        return cnt;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    vector<int> x = {12,12,30,24,24};
    auto a = sol.countCompleteDayPairs(x);

    return 0;
}
