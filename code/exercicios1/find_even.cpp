#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isEven(int x) {
        return !isOdd(x);
    }
    
    bool isOdd(int x) {
        return (x & 1);
    }
    
    int ndig(int x) {
        int i = 1;
        while (x /= 10) {
            i++;
        }
        return i;
    }
    
    int findNumbers(vector<int>& nums) {
        int evennums = 0;
        
        for (int x : nums) {
            
            if (isEven(ndig(x)))
                evennums++;
        }
        
        return evennums;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{12,345,2,6,7896};
    Solution s;
    int res = s.findNumbers(v);
    cout << res << endl;
    return 0;
}
