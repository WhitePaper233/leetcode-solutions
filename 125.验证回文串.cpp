/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cctype>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                s[i] = tolower(s[i]);
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            }
            s.erase(i, 1);
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[s.size() - 1 -i]) return false;
        }

        return true;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    cout << sol.isPalindrome("ab_a");

    return 0;
}