/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int i = 0, j = 0;
        for (; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                nums[j++] = nums[i];
            }
        }
        if (j - 1 >= 0 && nums[i] != nums[j - 1]) {
            nums[j] = nums[i];
        }
        return j + 1;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    vector<int> input = {1,1};
    sol.removeDuplicates(input);

    return 0;
}
