#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    inline int is_prime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 ||x == 19);
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        
        while (left <= right) {
            cnt += is_prime(__builtin_popcount(left));
            left++;
        }
        
        return cnt;
    }
};