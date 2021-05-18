#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled;

        for (vector<int>::iterator i = nums.begin(), j = nums.begin() + n; i < nums.begin() + n && j < nums.end(); i++, j++) {
            shuffled.push_back(*i);
            shuffled.push_back(*j);
        }

        return shuffled;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
