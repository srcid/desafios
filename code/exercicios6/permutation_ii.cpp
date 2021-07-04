#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return res;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;

    for (int i=1; i<argc; i++) {
        nums.push_back(atoi(argv[i]));
    }

    s.permuteUnique(nums);
    return 0;
}
