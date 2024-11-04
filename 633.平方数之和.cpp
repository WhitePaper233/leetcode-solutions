/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int64> nums {};
        for (int64 i = 0; i * i <= (int64)c; ++i) {
            nums.push_back(i * i);
        }

        unordered_set<int64> memo {};
        for (int i = 0; i < nums.size(); ++i) {
            memo.insert(c - nums[i]);
            if (memo.find(nums[i]) != memo.end()) return true;
        }

        return false;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    sol.judgeSquareSum(5);

    return 0;
}
