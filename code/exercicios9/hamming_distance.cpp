#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {        
        return __builtin_popcount(x^y);
    }
};

class Solution2 {
public:
    int hammingDistance(int x, int y) {        
        int r = x^y, cnt = 0;

        while (r) {
            cnt++;
            r>>=1;
        }

        return cnt;
    }
};