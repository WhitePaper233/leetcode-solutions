/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    void initDSU(vector<int>& parents, const vector<vector<int>>& edges) {
        parents.resize(edges.size() + 1);
        for (int i = 0; i < edges.size(); ++i) {
            parents[i] = i;
        }
    }

    int find(vector<int>& parents, int u) {
        return parents[u] == u ? u : parents[u] = find(parents, parents[u]);
    }

    void uni(vector<int>& parents, int u , int v) {
        parents[find(parents, u)] = find(parents, v);
    }

    bool same(vector<int>& parents, int u, int v) {
        return find(parents, u) == find(parents, v);
    }

    pair<int, int> getRemovableEdge(const vector<vector<int>>& edges) {
        vector<int> parents {};
        initDSU(parents, edges);
        for (auto edge : edges) {
            if (same(parents, edge[0], edge[1])) {
                return {edge[0], edge[1]};
            }
            uni(parents, edge[1], edge[0]);
        }
        return {};
    }

    bool checkIfEdgeRemoveable(const vector<vector<int>>& edges, int edgeIndex) {
        vector<int> parents {};
        initDSU(parents, edges);
        for (int i = 0; i < edges.size(); ++i) {
            if (i == edgeIndex) continue;
            
            auto edge = edges[i];
            if (same(parents, edge[0], edge[1])) {
                return false;
            }
            uni(parents, edge[1], edge[0]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 统计节点入度
        vector<int> inDegrees(edges.size() + 1, 0);
        for (int i = 0; i < edges.size(); ++i) {
            inDegrees[edges[i][1]]++;
        }

        // 统计入度为 2 的节点的边
        vector<int> duplicatedEdges {};
        for (int i = edges.size() - 1; i >= 0; --i) {
            if (inDegrees[edges[i][1]] == 2) {
                duplicatedEdges.push_back(i);
            }
        }

        // 如果存在入度为2的节点 则去除重复
        if (!duplicatedEdges.empty()) {
            if (checkIfEdgeRemoveable(edges, duplicatedEdges[0])) {
                return edges[duplicatedEdges[0]];
            } else {
                return edges[duplicatedEdges[1]];
            }
        }

        // 否则找环
        auto res = getRemovableEdge(edges);
        return {res.first, res.second};
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3}
    };
    sol.findRedundantDirectedConnection(edges);

    return 0;
}