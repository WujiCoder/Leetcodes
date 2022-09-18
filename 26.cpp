// 难度： 简单
// 题目描述：删除有序数组中的重复项
// url: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int slow = 0;
        int fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] == nums[fast]) {
                fast++;
            }
            else {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        return slow + 1;

    }
};