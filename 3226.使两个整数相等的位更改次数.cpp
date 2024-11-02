/*
 * @lc app=leetcode.cn id=3226 lang=cpp
 *
 * [3226] 使两个整数相等的位更改次数
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        string nBinary = toBinary(n), kBinary = toBinary(k);

        for (int i = 0; i < nBinary.size(); ++i) {
            if (nBinary[i] == '1' && kBinary[i] == '0') {
                cnt++;
                continue;
            }
            if (nBinary[i] == '0' && kBinary[i] == '1') {
                return -1;
            }
        }

        return cnt;
    }

    string toBinary(int num) {
        if (num == 0) return "0";
        string binary {};
        while (num > 0) {
            binary = (num % 2 ? "1" : "0") + binary;
            num /= 2;
        }

        if (binary.size() < 31) {
            binary = string(31 - binary.size(), '0') + binary;
        }

        return binary;
    }
};
// @lc code=end

