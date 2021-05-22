#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(), nums.end(), target);
        if (it == nums.begin()) {
            return 0;
        } else {
            return *(it-1) == target ? distance(nums.begin(), it-1) : distance(nums.begin(), it);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,5,6,9,15,36,52,52,52,52,74,74,63};
    Solution s;
    cout << s.searchInsert(nums, 1) << endl;
    return 0;
}
