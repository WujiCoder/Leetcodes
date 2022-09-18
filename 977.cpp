// 难度： 简单
// 题目描述： 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
// 请你设计时间复杂度为 O(n) 的算法解决本问题
// https://leetcode.cn/problems/squares-of-a-sorted-array/

// 解题思路：双指针法

#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> result = nums;

        while(left <= right) {
            if (nums[left] * nums[left] <= nums[right] * nums[right]) {
                result[index--] = nums[right] * nums[right];
                right--;
            }
            else {
                result[index--] = nums[left] * nums[left];
                left++;
            }
        }
        return result;

    }
};

int main() {
    int temp[] = {-4, -1, 0, 3, 10};
    vector<int> nums(temp, temp + sizeof(temp) / sizeof(int));
    Solution solution;
    vector<int> result = solution.sortedSquares(nums);
    cout << "Result: ";
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }

}
