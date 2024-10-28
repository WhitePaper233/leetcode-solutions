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
        solve(candidates, ans, {}, target);
        return ans;
    }

    void solve(const vector<int>& candidates, vector<vector<int>>& ans, vector<int> curr, int target) {
        int currSum = sum(curr);
        for (int num : candidates) {
            if (currSum + num == target) {
                vector<int> next = curr;
                next.push_back(num);
                if (!checkDuplicated(ans, next)) ans.push_back(next);
                continue;
            }
            if (currSum + num < target) {
                vector<int> next = curr;
                next.push_back(num);
                solve(candidates, ans, next, target);
            }
        }
    }

    int sum(vector<int>& vec) {
        int sum = 0;
        for (auto num : vec) {
            sum += num;
        }
        return sum;
    }

    bool checkDuplicated(vector<vector<int>>& ans, vector<int>& vec) {
        sort(vec.begin(), vec.end());

        for (auto arr : ans) {
            if (arr.size() != vec.size()) continue;

            bool flag = true;
            for (int i = 0; i < vec.size(); ++i) {
                if (arr[i] != vec[i]) {
                    flag = false;
                    break;
                };
            }

            if (flag) return true;
        }
        return false;
    }
};
// @lc code=end

