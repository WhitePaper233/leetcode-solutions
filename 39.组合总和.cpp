/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans {};
        solve(candidates, ans, {}, target, 0, 0);
        return ans;
    }

    void solve(
        const vector<int>& candidates, 
        vector<vector<int>>& ans, 
        vector<int> curr,
        int target,
        int currIndex,
        int currSum
    ) {
        for (int i = currIndex; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (currSum + num == target) {
                vector<int> next = curr;
                next.push_back(num);
                ans.push_back(next);
                continue;
            }
            if (currSum + num < target) {
                vector<int> next = curr;
                next.push_back(num);
                solve(candidates, ans, next, target, i, currSum + num);
            }
        }
    }
};
// @lc code=end

