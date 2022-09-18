// 难度： 简单
// 题目描述：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// url: https://leetcode-cn.com/problems/remove-element/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;

        for (int fasetIndex = 0; fasetIndex < nums.size(); fasetIndex++) {
            if (nums[fasetIndex] != val) {
                nums[slowIndex++] = nums[fasetIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    int temp[] = {-1, 0, 3, 5, 9, 12, 9};
    vector<int> nums(temp, temp + sizeof(temp) / sizeof(int));
    int val = 9;
    Solution solution;
    int slowIndex = solution.removeElement(nums, val);
    cout << "slowIndex: " << slowIndex << endl;
}