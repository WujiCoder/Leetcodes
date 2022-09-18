// 难度： 简单
// 题目描述：给定两个字符串ransomNote和magazine，判断ransomNote能不能由magazine里面的字符构成，如果可以，返回true，否则返回false。
// url: https://leetcode.cn/problems/ransom-note/

#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCnt[26] = {0};
        int i;
        if (ransomNote.size() > magazine.size()) return false;
        for (i = 0; i < magazine.size(); i++) {
            charCnt[magazine[i] - 'a']++;
        }
        for (i = 0; i < ransomNote.size(); i++) {
            charCnt[ransomNote[i] - 'a']--;
            if (charCnt[ransomNote[i]- 'a'] < 0) return false;
        }

        return true;
    }
};