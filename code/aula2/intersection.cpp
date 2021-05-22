#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersec;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        auto itr_nums1 = unique(nums1.begin(), nums1.end());
        auto itr_nums2 = unique(nums2.begin(), nums2.end());

        nums1.resize(distance(nums1.begin(), itr_nums1));
        nums2.resize(distance(nums2.begin(), itr_nums2));

        for (int x : nums1) {
            if (binary_search(nums2.begin(), nums2.end(), x)) {
                intersec.push_back(x);
            }
        }

        return intersec;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{1,2,2,1},
                nums2{2,2};
    Solution s;

    for (int x : s.intersection(nums1, nums2)) {
        cout << x << endl;
    }

    return 0;
}
