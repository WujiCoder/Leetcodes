// 难度： 中等
// 题目描述： 给定四个整数数组，数组长度都是n，请计算有多少个元祖(i, j, k, l)满足:
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
// https://leetcode.cn/problems/4sum-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>sumMap;
        int cnt = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                sumMap[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int offset = 0 - nums3[i] - nums4[j];
                if (sumMap.find(offset) != sumMap.end()) {
                    cnt += sumMap[offset];
                }
            }
        }
        return cnt;


    }
};