/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

#include <cmath>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int cnt = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            ++cnt;
            node = node->left;
        }

        if (cnt == 0) return 1;

        int i = pow(2, cnt), j = pow(2, cnt + 1) - 1;
        
        while (i < j && i != j - 1) {
            int m = i + (j - i) / 2;
            if (exist(cnt, m, root)) {
                i = m;
            } else {
                j = m - 1;
            }
        }
        if (exist(cnt, j, root)) return j;
        return i;
    }

    bool exist(int level, int num, TreeNode* root) {
        int mask = 1 << (level - 1);
        TreeNode* node = root;
        
        while (node != nullptr && mask > 0) {
            if (num & mask) {
                node = node->right;
            } else {
                node = node->left;
            }

            mask >>= 1;
        }

        return node != nullptr;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    auto n1 = TreeNode(1);
    auto n2 = TreeNode(2);
    auto n3 = TreeNode(3);
    auto n4 = TreeNode(4);
    auto n5 = TreeNode(5);
    auto n6 = TreeNode(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;

    sol.countNodes(&n1);

    return 0;
}
