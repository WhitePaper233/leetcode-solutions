/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    unordered_map<char, string> mapping = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        vector<string> ans { };
        solve(ans, digits);
        return ans;
    }

    void solve(vector<string>& ans, string digits) {
        if (digits.empty()) return;
        if (digits.size() > 1) {
            solve(ans, digits.substr(0, digits.size() - 1));
        }

        if (digits.size() == 1) {
            for (char new_back : this->mapping[digits[0]]) {
                string new_ele { };
                new_ele.push_back(new_back);
                ans.push_back(new_ele);
            }
            return;
        }

        vector<string> prev_ans = ans;
        ans.clear();
        for (string ele : prev_ans) {
            for (char new_back : this->mapping[digits[digits.size() - 1]]) {
                string new_ele = ele;
                new_ele.push_back(new_back);
                ans.push_back(new_ele);
            }
        }
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    auto x =sol.letterCombinations("23");

    return 0;
}
