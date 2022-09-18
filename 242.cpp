// 难度： 简单
// 题目描述：给定两个字符串s和t，判断s和t是否为字母异位词，即判断s和t中每个字符出现的次数是否都相同。
// url: https://leetcode.cn/problems/valid-anagram/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int record[26] = {0};
        int i;
        for (i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};