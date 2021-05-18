#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompress;

        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i += 2) {
            decompress.insert(decompress.end(),*i, *(i+1));
        }

        return decompress;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v{5,6,3,2};
    for (int x : s.decompressRLElist(v)) {
        cout << x << ","; 
    }
    cout << endl;

    return 0;
}
