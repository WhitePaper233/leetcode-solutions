/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 *
 * [3211] 生成不含相邻零的二进制字符串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans {};
        solve("", n, ans);
        return ans;
    }

    void solve(string currStr, int n, vector<string>& ans) {
        int len = currStr.size();
        if (len >= 2 && currStr[len - 1] == '0' && currStr[len - 2] == '0') {
            return;
        }
        if (len == n) {
            ans.push_back(currStr);
            return;
        }
        solve(currStr + "0", n, ans);
        solve(currStr + "1", n, ans);
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    string a = "11";
    a + "1";

    return 0;
}