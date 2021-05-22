#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        for (auto i = nums.begin(); i < nums.end(); i++) {
            for (auto j = i + 1; j < nums.end() && *i < target && *j < target; j++) {
                if ((*i) + (*j) == target) {
                    res.push_back(distance(nums.begin(), i));
                    res.push_back(distance(nums.begin(), j));
                    return res;
                }
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> nums{3,2,4};
    int target = 6;
    Solution s;

    for (int x : s.twoSum(nums,target)) {
        cout << x << endl;
    }
}
