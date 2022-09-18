// 难度： 简单
// 题目描述： 给定两个数组，返回他们的交集，返回结果中每个元素出现的次数应与元素
// 在两个数组中出现的次数一致，如果出现次数不一致，则考虑较小值，不考虑返回结果的输出顺序。
// https://leetcode.cn/problems/intersection-of-two-arrays-ii/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        vector<int> res;
        unordered_map<int, int> nums_map;
        for (int x: nums1) {
            nums_map[x]++;
        }
        for (int x: nums2) {
            if (nums_map.count(x)) {
                res.push_back(x);
                nums_map[x]--;
                if (nums_map[x] == 0) {
                    nums_map.erase(x);
                }
            }
        }
        return res;

    }
};
