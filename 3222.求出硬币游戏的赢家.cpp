/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn = min(x, y / 4);
        return turn % 2 ? "Alice" : "Bob";
    }
};
// @lc code=end
