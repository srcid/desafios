#include <bits/stdc++.h>

using namespace std;

template <class T>
void printvector(std::vector<T> v) {
    std::cout << "[";
    for_each(v.begin(), v.end()-1, [](T x){std::cout << x << ", ";});
    std::cout << v.back() << "]" << std::endl;
}

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
       sort(nums.begin(), nums.end(), [](int a, int b){return (a>b);});
       vector<int> res;
       int i, cur, acc;

       for (i=0; i<nums.size(); i++) {
           res.push_back(nums[i]);
           cur = accumulate(res.begin(), res.end(), 0);
           acc = accumulate(nums.begin()+i+1, nums.end(), 0);

           if (cur > acc) {
               break;
           }
       }

       return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr{4,3,10,9,8};
    Solution s;
    printvector(s.minSubsequence(arr));

    vector<int> arr2{4,4,7,6,7};
    printvector(s.minSubsequence(arr2));

    return 0;
}
