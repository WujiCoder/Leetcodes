// 难度： 中等
// 题目描述： 给定两个字符串s和p，找到s中所有p的异位词子串，返回这些子串的其实索引。不考虑答案输出的顺序。
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pCharCnt(26);
        vector<int> sCharCnt(26);
        int pLen = p.size();
        int sLen = s.size();
        vector<int> res;
        if (sLen < pLen) return res;

        int slow = 0, fast = slow + p.size() - 1;

        for (int i = 0; i < pLen; i++) {
            pCharCnt[p[i] - 'a']++;
            sCharCnt[s[i] - 'a']++;
        }
        while(fast < sLen){
            if (pCharCnt == sCharCnt) res.emplace_back(slow);
            sCharCnt[s[slow++] - 'a']--;
            fast++;
            if (fast < sLen) sCharCnt[s[fast] - 'a']++;


        }

        return res;
    }
};

int main() {
    string s = "acdcaeccde";
    string p = "c";
    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    cout << "res: ";
    for (auto x: res) {
        cout << x << " ";
    }


}


