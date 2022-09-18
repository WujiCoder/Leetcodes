// 难度： 中等
// 题目描述： 描述内容较多，见链接

//https://leetcode.cn/problems/fruit-into-baskets/

// 解题思路：滑动窗口，双指针法

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace  std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = INT32_MIN;
        int i = 0;
        unordered_map<int, int> buckets;
        for (int j = 0; j < fruits.size(); j++) {
            buckets[fruits[j]]++;
            while(buckets.size() > 2) {
                buckets[fruits[i]]--;
                if (buckets[fruits[i]] == 0)
                    buckets.erase(fruits[i]);
                i++;
            }

            int subLen = j - i + 1;
            maxFruits = maxFruits > subLen ? maxFruits : subLen;

        }
        return maxFruits == INT32_MIN ? 0 : maxFruits;
    }
};

int main() {
//    int temp[] = {1, 2, 3, 2, 2};
    int temp[] = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> fruits(temp, temp + sizeof(temp) / sizeof(int));
    Solution solution;
    int maxFruits = solution.totalFruit(fruits);
    cout << "maxFruits: " << maxFruits;

}
