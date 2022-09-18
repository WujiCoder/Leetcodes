// 难度： 中等
// 题目描述： 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// url: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int start = -1, end = -1;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    start = mid;
                    break;
                }
                else {
                    right = mid - 1;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    end = mid;
                    break;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {start, end};
    }
};

int main() {
    int temp[] = {-1, 0, 3, 5, 9, 9, 9, 10};
    vector<int> nums(temp, temp + sizeof(temp) / sizeof(int));
    int target = 9;
    Solution solution;
    vector<int> res = solution.searchRange(nums, target);
    cout << "start: " << res[0] << ", end: " << res[1] << endl;
}