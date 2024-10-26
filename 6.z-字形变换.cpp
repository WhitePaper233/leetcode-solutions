/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string convert(string s, int numRows) {
        int groupSize = 2 * numRows - 2 == 0 ? 1 : 2 * numRows - 2;
        vector<vector<char>> buf = vector<vector<char>>(
            numRows, vector<char>()
        );

        for (int i = 0; i < s.size(); i += groupSize) {
            buf[0].push_back(s[i]);
            int head = i + 1, tail = i + groupSize - 1;
            while (head <= tail) {
                if (head == tail) {
                    if (head < s.size()) buf[numRows - 1].push_back(s[head]);
                    break;
                }
                if (head < s.size()) buf[head - i].push_back(s[head]);
                if (tail < s.size()) buf[head - i].push_back(s[tail]);
                head++; tail--;
            }
        }
        
        string ret { };
        for (auto line : buf) {
            for (auto word : line) ret.push_back(word);
        }

        return ret;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    cout << sol.convert("A", 1);

    return 0;
}