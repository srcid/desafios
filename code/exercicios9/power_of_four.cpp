#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n>0 && __builtin_popcount(n)==1 && !(__builtin_ctz(n)&1));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << (s.isPowerOfFour(atoi(argv[1])) ? "true" : "false") << endl;
    return 0;
}
