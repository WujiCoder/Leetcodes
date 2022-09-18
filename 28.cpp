// 难度： 中等
// 题目描述：给你两个字符串haystack和needle，请你在haystack字符串中找出needle字符串的第一个匹配项的下标（下标从0开始）
//         如果needle不是haystack的一部分，则返回-1。
// url: https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        // 初始化
        int j = 0; //当前前缀的末尾位置
        next[j] = 0;
        // i表示模式串的索引，其在next数组的对应索引处表示的是i包括i之前的子串的最长相等前后缀的长度
        for(int i = 1; i < s.size(); i++) {
            while(j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = 0; // next数组起始位置
        for(int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;

    }
};