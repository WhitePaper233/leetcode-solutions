/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans {};
        solve({n, n}, "", ans);
        return ans;
    }

    void solve(pair<int, int> leftParenthesis, string curr, vector<string>& ans) {
        if (leftParenthesis.first == 0 && leftParenthesis.second == 0) {
            ans.push_back(curr);
            return;
        }
        if (leftParenthesis.first > 0) {
            string next = curr;
            next.push_back('(');
            solve({leftParenthesis.first - 1, leftParenthesis.second}, next, ans);
        }
        if (leftParenthesis.second > 0 && leftParenthesis.second > leftParenthesis.first) {
            string next = curr;
            next.push_back(')');
            solve({leftParenthesis.first, leftParenthesis.second - 1}, next, ans);
        }
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    auto x =sol.generateParenthesis(3);

    return 0;
}
