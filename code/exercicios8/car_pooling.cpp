#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> p;
        int acc;
        
        acc = 0;
        
        for (auto trip : trips) {
            p[trip[1]] += trip[0];
            p[trip[2]]  -= trip[0];
        }
        
        for (auto i = p.begin(); i != p.end(); i++) {
            acc += i->second;
            
            if (acc > capacity) return false;
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> trips{{2,1,5},{3,3,7}};
    int capacity = 4;
    Solution s;

    cout << s.carPooling(trips, capacity) << endl;
    
    return 0;
}
