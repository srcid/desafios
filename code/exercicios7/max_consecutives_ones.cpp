#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        
        vector<int>::iterator i, j;
        int ans=0, dis;
        
        i=nums.begin();
        
        while (i<nums.end()) {
            
            if (*i) {
                j=i+1;
                
                while (j<nums.end() && *j) j++;
                
                dis=distance(i,j);
                i=j;
                
                if (dis > ans) ans=dis;
                
            } else {
                i++;
            }
        }
        
        return ans;
    }
};