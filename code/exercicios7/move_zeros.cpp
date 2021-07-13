#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size()==1) {
            return;
        } else if (nums.size()==2) {
            if (!nums[0]) {
                swap(nums[0], nums[1]);
            }
        }
        
        vector<int>::iterator i, j;
        
        for (i=nums.begin(); i<nums.end(); i++) {
            // encontrou um 0
            if (!(*i)) {
                // j é o primeiro elemento não 0
                for (j=i+1; j<nums.end(); j++) {
                    if (*j) {
                        swap(*i, *j);
                        break;
                    }
                }
            }
        }
    }
};