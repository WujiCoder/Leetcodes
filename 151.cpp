// 难度： 中等
// 题目描述：反转字符串中的单词
// url: https://leetcode.cn/problems/reverse-words-in-a-string/

#include <iostream>
using namespace std;

class Solution {
public:
    void removeExtraSpaces(string &s) {
        int slow = 0;
        int fast = 0;
        for(; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (s[fast] != ' ' && fast < s.size()) {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string &s, int left, int right) {
        while(right > left) {
            swap(s[left], s[right]);
            right--;
            left++;
        }

    }
    string reverseWords(string s) {
        // 先去除多余空格
        removeExtraSpaces(s);
        // 字符串整体反转
        reverse(s, 0, s.size() - 1);

        // 单词再反转一次，恢复单词原来的顺序
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;

    }
};