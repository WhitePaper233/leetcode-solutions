/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = chars.size() - 1, j = i;
        while (j >= 0) {
            if (i >= 0 && chars[i] == chars[j]) {
                --i;
                continue;
            }

            if (j - i > 1) {
                auto cnt_str = to_string(j - i);
                chars.insert(chars.begin() + j + 1, cnt_str.begin(), cnt_str.end());
            }

            while (j > i + 1) {
                chars.erase(chars.begin() + j, chars.begin() + j + 1);
                --j;
            }
            j = i;
        }
        return chars.size();
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<char> chars = {'a', 'a','b','b','c','c','c'};
    sol.compress(chars);

    return 0;
}