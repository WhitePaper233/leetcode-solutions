/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int64, int64> memo {};
        int64 cnt = 0;

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

