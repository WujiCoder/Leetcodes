
// 难度： 简单
// 题目描述：移动0，给定一个数组nums，编写一个函数将所有0移动到数组末尾，同时保持非0元素的相对顺序
// url: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};