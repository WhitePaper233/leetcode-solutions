/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto minmax_ele = minmax_element(nums.begin(), nums.end());
        int diff = *minmax_ele.second - *minmax_ele.first;
        if (diff <= 2 * k) return 0;
        else return diff - 2 * k;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<int> x = {0, 10};
    sol.smallestRangeI(x, 2);

    return 0;
}
