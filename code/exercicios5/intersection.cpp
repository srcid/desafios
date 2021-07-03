#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersec;
        unordered_map<int,int> frq;
        
        for (int n : nums1) {
            frq[n]=1;
        }
        
        for (int n : nums2) {
            if (frq[n]) {
                frq[n]=0;
                intersec.push_back(n);
            }
        }
        
        return intersec;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    Solution s;
    auto res = s.intersection(nums1, nums2);

    for_each(res.begin(), res.end()-1, [](auto x){cout << x << ", "});
    cout << res.back() << endl;

    return 0;
}
