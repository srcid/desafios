#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frq;
        map<int,int> vals;
        
        for (int n : arr) {
            frq[n]++;
        }
        
        for (auto e : frq) {
            if (++vals[e.second] > 1) {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr{-3,0,1,-3,1,1,1,-3,10,0};
    Solution s;

    cout << s.uniqueOccurrences(arr) << endl;
    
    return 0;
}
