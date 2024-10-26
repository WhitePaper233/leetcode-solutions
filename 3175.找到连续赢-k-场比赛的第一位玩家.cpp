/*
 * @lc app=leetcode.cn id=3175 lang=cpp
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    // int findWinningPlayer(vector<int>& skills, int k) {
    //     unordered_map<int, int> counter {};
    //     list<pair<int, int>> indexedSkills {};

    //     for (int i = 0; i < skills.size(); ++i) {
    //         counter.insert({i, 0});
    //         indexedSkills.push_back({i, skills[i]});
    //     }
        
    //     for (int i = 1; i < skills.size(); ++i) {
    //         auto firstElem = indexedSkills.begin(), secondElem = next(firstElem);
    //         if (firstElem->second > secondElem->second) {
    //             counter[firstElem->first]++;
    //             indexedSkills.erase(secondElem);
    //             if (counter[indexedSkills.begin()->first] == k) break;
    //         } else {
    //             counter[secondElem->first]++;
    //             indexedSkills.erase(firstElem);
    //             if (counter[indexedSkills.begin()->first] == k) break;
    //         }
    //     }

    //     return indexedSkills.begin()->first;
    // }

    int findWinningPlayer(vector<int>& skills, int k) {
        int cnt = 0, winner = skills[0], winnerPos = 0;
        for (int i = 1; i < skills.size(); ++i) {
            if (cnt == k) break;
            
            if (winner > skills[i]) {
                cnt++;
            } else {
                winner = skills[i];
                winnerPos = i;
                cnt = 1;
            }
        }
        return winnerPos;
    }
};
// @lc code=end
int main() {
    auto sol = Solution();

    vector<int> b = {2,5,4};
    auto x = sol.findWinningPlayer(b, 3);

    return 0;
}
