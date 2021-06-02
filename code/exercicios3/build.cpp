#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        auto it = target.begin();
        vector<string> ops;
        int i = 1;
        
        while (it != target.end()) {
            ops.push_back("Push");
            
            if (i < *it) {
                ops.push_back("Pop");
            } else {
                it++;
            }
            
            i++;
        }  
        
        return ops;
    }
};
