// 难度： 简单
// 题目描述： 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
// 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// url: https://leetcode-cn.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return right + 1;
    }
};

int main()
{
    int temp[] = {1, 3, 5, 6};
    vector<int> nums(temp, temp + sizeof(temp) / sizeof(int));
    int target = 5;
    Solution solution;

    int position = solution.searchInsert(nums, target);
    cout << position << endl;
}
