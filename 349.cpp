// 难度： 简单
// 题目描述： 给定两个数组，返回他们的交集，不考虑返回结果的输出顺序。
// https://leetcode.cn/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int x: nums2) {
            if (nums_set.find(x) != nums_set.end()) {
                res.insert(x);
            }
        }
        return vector<int>(res.begin(), res.end());

    }
};

