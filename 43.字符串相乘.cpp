/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            num1 = string(num2.size() - num1.size(), '0') + num1;
        } else if (num2.size() < num1.size()) {
            num2 = string(num1.size() - num2.size(), '0') + num2;
        }

        num1.insert(num1.begin(), '0'); num2.insert(num2.begin(), '0'); 

        vector<string> arr {};
        string per {};
        int c = 0, cnt = 0;
        for (int i = num2.size() - 1; i > -1; --i) {
            for (int j = num1.size() - 1; j > -1; --j) {
                int curr = (num2[i] - '0') * (num1[j] - '0');
                curr += c;
                per.insert(per.begin(), curr % 10 + '0');
                c = curr / 10;
            }

            arr.push_back(per + string(cnt, '0'));

            c = 0, cnt++;
            per.clear();
        }

        string ans { "0" };
        for (auto p : arr) {
            ans = add(ans, p);
        }
        
        cnt = 0;
        for (int i = 0; i < ans.size() - 1; ++i) {
            if (ans[i] == '0') cnt++;
            else break;
        }

        return ans.substr(cnt);
    }

    string add(string num1, string num2) {
        string ans {};
        if (num1.size() < num2.size()) {
            num1 = string(num2.size() - num1.size(), '0') + num1;
        } else if (num2.size() < num1.size()) {
            num2 = string(num1.size() - num2.size(), '0') + num2;
        }
        
        int c = 0;
        for (int i = num1.size() - 1; i > -1; --i) {
            int curr = (num1[i] - '0') + (num2[i] - '0');
            curr += c;
            ans.insert(ans.begin(), curr % 10 + '0');
            c = curr / 10;
        }

        return ans;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    string x = sol.multiply("0", "0");

    return 0;
}
