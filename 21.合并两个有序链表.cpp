/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* merged = nullptr, *mergedHead;
        if (list1->val < list2->val) {
            merged = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            list2 = list2->next;
        }
        mergedHead = merged;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }

        if (list1 != nullptr) {
            merged->next = list1;
        } else {
            merged->next = list2;
        }

        return mergedHead;
    }
};
// @lc code=end
