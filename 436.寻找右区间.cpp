/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res; vector<pair<int, int>> firstPairs;
        for (int i = 0; i < intervals.size(); ++i) {
            firstPairs.push_back({intervals[i][0], i});
        }
        sort(firstPairs.begin(), firstPairs.end());

        for (auto range : intervals) {
            int i = 0, j = firstPairs.size() - 1, m;
            while (i <= j) {
                m = i + (j - i) / 2;
                if (firstPairs[m].first < range[1]) i = m + 1;
                else j = m - 1;
            }
            if (i >= firstPairs.size()) res.push_back(-1);
            else res.push_back(firstPairs[i].second);
        }
        return res;
    }
}; 
// @lc code=end

int main() {
    auto sol = Solution();

    vector<vector<int>> a = {{3, 4}, {2, 3}, {1, 2}};
    auto b = sol.findRightInterval(a);

    return 0;
}
