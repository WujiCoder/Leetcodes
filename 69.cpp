// 难度： 简单
// 题目描述：给你一个非负整数 x ，计算并返回 x 的 算术平方根 。由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
// url: https://leetcode.cn/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (mid == x / mid) return mid;
            else if (mid < x / mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;

    }
};

