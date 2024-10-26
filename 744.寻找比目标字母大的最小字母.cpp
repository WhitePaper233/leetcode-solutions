/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0, j = letters.size() - 1, m;
        int pos = -1; char ls = 'z' + 1;

        while (i <= j) {
            m = i + (j - i) / 2;
            if (letters[m] <= target) {
                i = m + 1;
            } else {
                j = m - 1;
            }

            if (letters[m] > target && letters[m] < ls) {
                pos = m;
                ls = letters[m];
            }
        }

        return pos == -1 ? letters[0] : ls;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<char> t = {'c', 'f', 'j'};
    sol.nextGreatestLetter(t, 'c');

    return 0;
}
