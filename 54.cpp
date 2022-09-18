
// 难度： 中等
// 题目描述： 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素

//https://leetcode.cn/problems/spiral-matrix/

// 解题思路：模拟题，考察边界处理

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int i, j;
        int loop = min(m / 2, n / 2);
        vector<int> res;

        while(loop--) {
            for(j = starty; j < n - offset; j++) {
                res.push_back(matrix[startx][j]);
            }
            for(i = startx; i < m - offset; i++) {
                res.push_back(matrix[i][j]);
            }

            for(; j > starty; j--) {
                res.push_back(matrix[i][j]);
            }

            for(; i > startx; i--) {
                res.push_back(matrix[i][j]);
            }

            startx++;
            starty++;
            offset++;
        }

        if (starty == n - offset) {
            for (i = startx; i <= m - offset; i++) {
                res.push_back((matrix[i][starty]));
            }
        }
        else if (startx == m - offset) {
            for (j = starty; j <= n - offset; j++) {
                res.push_back((matrix[startx][j]));
            }
        }

        return res;
    }
};

int main() {
//    int temp[] = {1, 2, 3, 2, 2};
    int temp[] = {3,3,3,1,2,1,1,2,3,3,4};
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    vector<int> res = solution.spiralOrder(matrix);
    for(auto c: res) cout << c << ", ";

}
