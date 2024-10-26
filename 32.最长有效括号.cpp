/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, int>> bracketStack {};
        string mask = string(s.size(), '0');

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                bracketStack.push({'(', i});
                continue;
            }
            if (!bracketStack.empty() && bracketStack.top().first == '(') {
                mask[bracketStack.top().second] = '1';
                mask[i] = '1';
                bracketStack.pop();
            }
        }

        int record = 0;
        for (int i = 0, j = 0; j <= mask.size(); ++j) {
            if (j != mask.size() && mask[i] == mask[j]) continue;

            if (mask[i] == '1') record = max(j - i, record);
            i = j;
        }

        return record;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    auto x = sol.longestValidParentheses("(");

    return 0;
}
