// 难度：简单
// 题目描述：给定一个n个元素有序的（升序）整型数组nums和一个目标值target,
//         写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。
// url: https://leetcode-cn.com/problems/binary-search/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            // 计算区间中间的下标（如果left、right都比较大的情况下，left + right就有可能会溢出
            int middle = left + (right - left) >> 1;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return -1;
    }
};

int main()
{
    int temp[] = {-1, 0, 3, 5, 9, 12, 9};
    vector<int> nums(temp, temp + sizeof(temp) / sizeof(int));
    int target = 9;
    Solution solution;
    int position = solution.search(nums, target);
    cout << position << endl;
}

