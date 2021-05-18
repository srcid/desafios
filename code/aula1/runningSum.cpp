#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<int> runningSum(vector<int>& nums) {

        vector<int> acc;

        if (nums.size() > 1) {
            
            acc.push_back(nums.at(0));

            for (int i = 1; i < nums.size(); i++) {
                acc.push_back(nums.at(i) + acc.at(i-1));
            }
        
        } else {

            if (nums.size() == 1) {
                acc.push_back(nums.at(0));
            }

        }

        return acc;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4};
    Solution s;

    for (int i : s.runningSum(nums)) {
        cout << i << endl;
    }

    return 0;
}
