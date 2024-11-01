/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int queueSize = n + 1;
        queue<ListNode*> lastNNodes {};
        for (int i = 0; i < queueSize; ++i) {
            lastNNodes.push(nullptr);
        }

        ListNode* node = head;
        while (node != nullptr) {
            lastNNodes.pop();
            lastNNodes.push(node);
            node = node->next;
        }
        
        // 正常情况 将队头 next 设置为 队列第三个元素
        if (lastNNodes.front() != nullptr && queueSize > 2) {
            auto front = lastNNodes.front();
            lastNNodes.pop();
            lastNNodes.pop();
            front->next = lastNNodes.front();
            return head;
        }

        // Case 2 队头为 nullptr 寻找 pop 前两个元素后第一个元素 若队列长度小于等于 2 则直接返回 nullptr
        if (lastNNodes.front() == nullptr) {
            if (queueSize > 2) {
                lastNNodes.pop();
                lastNNodes.pop();
                return lastNNodes.front();
            } else {
                return nullptr;
            }
        }

        // Case 3 队头不为 nullptr 且队长度为 2
        if (lastNNodes.front() != nullptr && queueSize == 2) {
            lastNNodes.front()->next = nullptr;
            return head;
        }

        return nullptr;
    }
};
// @lc code=end

int main() {
    auto sol = Solution();

    auto a = new ListNode(1);
    auto b = new ListNode(2);
    auto c = new ListNode(3);
    auto d = new ListNode(4);
    auto e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    
    auto x = sol.removeNthFromEnd(a, 2);

    return 0;
}
