// 难度：简单
// 题目描述：给定s和t两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回true。#代表退格字符
// url: https://leetcode.cn/problems/backspace-string-compare/

#include <iostream>
using namespace std;

// 使用栈的思想解决这个问题，时间复杂度O(m + n), 空间复杂度O(m + n)
class Solution1 {
public:

    bool backspaceCompare(string s, string t) {
        string S, T;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') S += s[i];
            else if (!S.empty()) S.pop_back();
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') T += t[i];
            else if (!T.empty()) T.pop_back();
        }
        if (S == T) return true;
        else return false;


    }
};

// 思路参考： https://code-thinking.cdn.bcebos.com/gifs/844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.gif
// 时间复杂度O(m + n)，空间复杂度O(1)

class Solution2 {
public:
    void jump(const string &x, int &i, int &skipNum) {
        while (i >= 0) {
            if (x[i] == '#') skipNum++;
            else if (skipNum) skipNum--;
            else break; //当前位置的字符不为#，且skipNum为0，代表当前字符需要直接比较，所以，直接跳出
            i--;
        }
    }
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int sSkipNum = 0, tSkipNum = 0;
        while (i >= 0 || j >= 0) {
            jump(s, i, sSkipNum);
            jump(t, j, tSkipNum);
            if (i < 0 || j < 0) break; //字符串s或者t遍历结束
            if (s[i] != t[j]) return false; //字符串s和t当前待比较字符
            i--; //获得s下一个字符的索引位置
            j--; //获得t下一个字符的索引位置
        }
        return i < 0 && j < 0; //s和t同时遍历完毕则说明两个字符串相同

    }
};