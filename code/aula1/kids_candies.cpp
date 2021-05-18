#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        
        for (int q : candies) {
            res.push_back(q + extraCandies >= max ? true : false);
        }
        
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> candies{2,3,5,1,3};
    int extraCandies = 3;
    Solution s;

    cout << "[";
    for (bool b : s.kidsWithCandies(candies, extraCandies)) {
        cout << (b ? " true" : " false");
    }
    cout << " ]" << endl;

    return 0;
}
