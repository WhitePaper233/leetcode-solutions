/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int mySqrt(int x) {
        int64 i = 0, j = x;

        int64 m;
        while (i <= j) {
            m = i + (j - i) / 2;
            if (m * m == x) return m;
            if (m * m > x && (m - 1) * (m - 1) < x) return m - 1;
            if (m * m < x && (m + 1) * (m + 1) > x) return m;

            if (m * m > x) j = m - 1;
            else if (m * m < x) i = m + 1;
        }

        return 0;
    }
};
// @lc code=end

