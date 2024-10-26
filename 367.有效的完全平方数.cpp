/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 4) {
            if (num == 3) return false;
            return true;
        }

        int i = 2, j = num / 2 + 1, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            int64 mSquared = static_cast<int64>(m) * m;
            if (mSquared < num) i = m + 1;
            else if (mSquared > num) j = m - 1;
            else return true;
        }

        return false;
    }
};
// @lc code=end

