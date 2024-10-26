/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.at(0).size(), cnt = 0;

        if (m == 1) {
            for (auto line : grid) {
                if (line.at(0) < 0) cnt++;
            }
            return cnt;
        }
        
        for (auto line : grid) {
            if (line[0] < 0) {
                cnt += line.size();
                continue;
            }

            int i = 0, j = line.size() - 2;

            while (i <= j) {
                int m = i + (j - i) / 2;

                if (line[m] < 0) {
                    j = m - 1;
                } else {
                    if (line[m + 1] < 0) {
                        cnt += line.size() - 1 - m;
                        break;
                    };
                    i = m + 1;
                }
            }
        }

        return cnt;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

        // 测试用例
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    sol.countNegatives(grid);

    return 0;
}