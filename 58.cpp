#include <iostream>
using namespace std;

// Solution1
class Solution1 {
public:
    string reverseLeftWords(string s, int n) {
        s.resize(s.size() + n);
        for (int i = 0; i < n; i++) {
            s[s.size() - n + i] = s[i];
        }
        return s.substr(n);

    }
};

// Solution2
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};