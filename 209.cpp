// 难度： 中等
// 题目描述： 给定一个含有n个正整数的数组和一个正整数 target 。
//          找出该数组中满足其和 ≥ target 的长度最小的 连续
//          子数组并返回其长度。如果不存在符合条件的子数组，返回 0 。

//https://leetcode.cn/problems/minimum-size-subarray-sum/

// 解题思路：滑动窗口，双指针法

#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int result = INT32_MAX;;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                int subLen = j - i + 1;
                result = result < subLen ? result : subLen;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;

    }
};