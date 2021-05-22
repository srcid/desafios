#include <bits/stdc++.h>

using namespace std;

/*
Abordagem utilizada consome muita memoria
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        unordered_map <int,int> map_count;
        priority_queue <int> q(nums.begin(), nums.end());
        int cur;

        while (!q.empty()) {
            cur = q.top();
            q.pop();

            while (!q.empty() && cur == q.top()) {
                q.pop();
            }

            map_count[cur] = q.size();
        }

        for (int i : nums) {
            res.push_back(map_count[i]);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{8,1,2,2,3};
    Solution s;
    for (int i : s.smallerNumbersThanCurrent(nums)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
