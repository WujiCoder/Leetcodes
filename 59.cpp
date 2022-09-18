
// 难度： 中等
// 题目描述： 螺旋矩阵

//https://leetcode.cn/problems/spiral-matrix-ii/

// 解题思路：模拟题，考察边界处理

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int startx, starty = 0;
        int offset = 1;
        int count = 1;
        int loop = n / 2;
        int mid = n / 2;
        int i, j;

        vector<vector<int>> res(n, vector<int>(n, 0));
        while (loop--) {
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty ; j--) {
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset += 1;
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;

    }
};
