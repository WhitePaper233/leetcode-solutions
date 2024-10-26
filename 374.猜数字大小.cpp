/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n, m;
        while (i <= j) {
            m = i + (j - i) / 2;
            int res = guess(m);
            if (res == 0) {
                return m;
            } else if (res == -1) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

