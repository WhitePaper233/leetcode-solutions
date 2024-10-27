/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    int find(vector<int>& parents, int u) {
        return parents[u] == u ? u : parents[u] = find(parents, parents[u]);
    }

    void uni(vector<int>& parents, int u, int v) {
        parents[find(parents, u)] = find(parents, v);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            auto edge = edges[i];

            if (find(parents, edge[0]) != find(parents, edge[1])) {
                uni(parents, edge[0], edge[1]);
            } else {
                return edge;
            }
        }

        return {};
    }
};
// @lc code=end

