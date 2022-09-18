#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> existMap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int searchValue = target - nums[i];
            auto iter = existMap.find(searchValue);
            if (iter != existMap.end()) {
                res.push_back(iter -> second);
                res.push_back(i);
            }
            else {
                existMap.insert(pair<int, int>(nums[i], i));
            }
            // if (existMap.count(target - nums[i])) {
            //     res.push_back(existMap[target - nums[i]]);
            //     res.push_back(i);
            // }
            // else {
            //     existMap[nums[i]] = i;
            // }
        }
        return res;

    }
};