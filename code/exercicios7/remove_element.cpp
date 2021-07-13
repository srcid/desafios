#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0]!=val;
        }
        
        vector<int>::iterator beg, end;
        beg=nums.begin();
        end=nums.end();
        
        while (beg < end) {
            
            if (*beg == val) {
                end--;
                swap(*beg, *end);
            } else {
                beg++;
            }
            
        }
        
        return distance(nums.begin(), end);
    }
};