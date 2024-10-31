/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
using int64 = int64_t;

class NumArray {
    vector<int> treeHeap {};
    int numsSize;

    void build(int i, int j, int currRoot, vector<int>& nums) {
        if (i == j) {
            treeHeap[currRoot] = nums[i];
            return;
        }

        int m = i + ((j - i) >> 1);
        build(i, m, currRoot * 2, nums);
        build(m + 1, j, currRoot * 2 + 1, nums);

        treeHeap[currRoot] = treeHeap[currRoot * 2] + treeHeap[currRoot * 2 + 1];
    }

    int update(int i, int j, int currRoot, int index, int val) {
        if (i == j) {
            int diff = val - treeHeap[currRoot];
            treeHeap[currRoot] = val;
            return diff;
        }

        int m = i + ((j - i) >> 1);
        int diff;
        if (i <= index && index <= m) {
            diff = update(i, m, currRoot * 2, index, val);
        } else {
            diff = update(m + 1, j, currRoot * 2 + 1, index, val);
        }
        treeHeap[currRoot] += diff;

        return diff;
    }

    int getSum(int i, int j, int currRoot, int ti, int tj) {
        if (ti <= i && j <= tj) {
            return treeHeap[currRoot];
        }

        int m = i + ((j - i) >> 1), sum = 0;
        if (ti <= m) sum += getSum(i, m, currRoot * 2, ti, tj);
        if (tj > m) sum += getSum(m + 1, j, currRoot * 2 + 1, ti, tj);

        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        numsSize = nums.size();
        treeHeap.resize(4 * numsSize);
        build(0, numsSize - 1, 1, nums);
    }
    
    void update(int index, int val) {
        update(0, numsSize - 1, 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, numsSize - 1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> a = {1, 3, 5};
    NumArray* obj = new NumArray(a);

    auto k = obj->sumRange(0, 2);
    obj->update(1, 2);
    obj->sumRange(0, 2);

    return 0;
}