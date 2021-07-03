#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> frq;
        
        for (auto n : nums) {
            if (++frq[n] > 1) {
                return n;
            }
        }
        
        return 0;
    }
};