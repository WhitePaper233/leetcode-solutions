/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prevStr = countAndSay(n - 1);
        string newStr { };
        for (int i = 0, j = 0; j <= prevStr.size(); ++j) {
            if (j == prevStr.size()) {
                newStr.append(to_string(j - i));
                newStr.push_back(prevStr[i]);
                break;
            }
            if (prevStr[i] != prevStr[j]) {
                newStr.append(to_string(j - i));
                newStr.push_back(prevStr[i]);
                i = j;
            }
        }
        return newStr;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    for (int i = 1; i < 24; ++i) {
        cout << sol.countAndSay(i) << '\n';
    }

    return 0;
}
