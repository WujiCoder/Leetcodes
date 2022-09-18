// 难度： 简单
// 题目描述： 编写一个算法判断一个数n是不是快乐数，快乐数定义参见链接里的定义。
// https://leetcode.cn/problems/happy-number/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sumSet;
        while (true) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            if (sum == 1) return true;

            if (sumSet.find(sum) != sumSet.end()) {
                return false;
            }
            else {
                sumSet.insert(sum);
            }
            n = sum;
        }

    }
};