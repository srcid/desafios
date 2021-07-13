#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void swap(vector<int>::iterator a, vector<int>::iterator b) {
        auto tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
        auto i = begin;
        
        for (auto cur = begin; cur < end-1; cur++) {
            if (*cur < *(end-1)) {
                swap(i, cur);
                i++;
            }
        }
        
        swap(i, end-1);
        
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int pos = nums.size()-k,
            dis;
        vector<int>::iterator beg = nums.begin(),
                              end = nums.end(),
                              p;

        while (beg != end) {
            for_each(beg, end, [](auto x){cout << x << " ";});
            cout << endl;

            p = partition(beg, end);
            dis = distance(nums.begin(), p);

            if (dis < pos) {
                beg = p+1;
            } else if (dis > pos) {
                end = p;
            } else {
                break;
            }
        }

        return *p;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int k, i;
    Solution s;

    k = atoi(argv[1]);
    
    for (i=2; i<argc; i++) {
        arr.push_back(atoi(argv[i]));
    }

    cout << s.findKthLargest(arr, k) << endl;
    return 0;
}
