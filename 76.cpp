
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        int i = 0;
        int cnt = 0;
        string res;
        for (auto c: t) ht[c]++;
        for (int j = 0; j <s.size(); j++) {
            hs[s[j]]++;
            if (hs[s[j]] <= ht[s[j]]) cnt++;

            while(hs[s[i]] > ht[s[i]]) {
                hs[s[i++]]--;
            }
            if (cnt == t.size()) {
                int subLen = j - i + 1;
                if (res.empty() || subLen < res.size())
                    res = s.substr(i, subLen);
            }
        }
        return res;

    }
};