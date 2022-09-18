// 难度： 中等
// 题目描述：给定一个非空的字符串s，检查是否可以通过由它的一个子串重复多次组成
// url: https://leetcode.cn/problems/repeated-substring-pattern/


#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;
        int j = 0;
        int next[s.size()];
        next[j] = 0;

        for (int i = 1; i < s.size(); i++) {
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;
        else return false;
    }
};