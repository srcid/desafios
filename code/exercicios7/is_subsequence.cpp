#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        string::iterator i, j;
        int match=0;
        
        for (i=s.begin(), j=t.begin(); i<s.end(); i++) {
            while (j<t.end()) {
                if (*i==*j) {
                    match=1;
                    j++;
                    break;
                }
                j++;
            }
            
            if (!match) {
                return false;
            }
            
            match=0;
        }
        
        return true;
    }
};