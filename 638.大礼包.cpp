/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 过滤价格更贵的礼包
        vector<int> whiteList(special.size(), true);
        for (int i = 0; i < special.size(); ++i) {
            int sum = 0; auto spec = special[i];
            for (int j = 0; j < spec.size() - 1; ++j) {
                sum += spec[j] * price[j];
            }
            if (spec.back() > sum) whiteList[i] = false;
        }

        return solve(price, special, whiteList, needs);
    }

    int solve(const vector<int>& price, const vector<vector<int>>& special, const vector<int>& whiteList, vector<int> needs) {
        // 单独购买所有物品所需的价格
        int sum = 0;
        for (int i = 0; i < needs.size(); ++i) {
            sum += price[i] * needs[i];
        }

        for (int i = 0; i < special.size(); ++i) {
            if (!whiteList[i]) continue;
            auto spec = special[i];
            vector<int> newNeeds = needs;
            bool avaliable = true;
            for (int j = 0; j < newNeeds.size(); ++j) {
                newNeeds[j] -= spec[j];
                if (newNeeds[j] < 0) {
                    avaliable = false;
                    break;
                }
            }
            if (!avaliable) continue;

            sum = min(sum, solve(price, special, whiteList, newNeeds) + spec.back());
        }
        return sum;
    }
};
// @lc code=end
