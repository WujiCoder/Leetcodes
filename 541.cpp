// 难度： 简单
// 题目描述：反转字符串II，给定一个字符串s和一个整数k，从字符串开头算起，每计数至2k个字符，就反转这2k个字符中的前k个字符
// url: https://leetcode.cn/problems/reverse-string-ii/

#include <iostream>
using namespace std;

// 建立新的数组来完成替换
class Solution1 {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k) {
            int left = i;
            int right = i + k - 1;
            if (right >= s.size()) right = s.size() - 1;
            while (right > left) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

        }
        return s;


    }
};

// 双指针法，不需要开辟新的数组，空间复杂度为O(1)
class Solution2 {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') cnt++;
        }
        int sOldSize = s.size();
        s.resize(s.size() + 2 * cnt);

        for (int i = sOldSize, j = s.size(); i < j; i--, j--) {
            if (s[i] != ' ') s[j] = s[i];
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;

    }
};