#include <bits/stdc++.h>

using namespace std;

template <class iterator>
void print_each(iterator begin, iterator end) {
    if (begin != end) {
        cout << '[' << *begin;
        for_each(begin+1, end, [](auto x){
            cout << ',' << x;
        });
        cout << ']' << endl;
    } else {
        cout << "Ø" << endl;
    }
}

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i,j;
        vector<int> p;

        i = 0;
        for_each(nums.begin(), nums.end(), [&p, &i](auto e){
            i += e;
            p.push_back(i);
        });

        print_each(p.begin(), p.end());

        j = 0;
        for (i=0; i<nums.size(); i++) {
            cout << p[i]-nums[i] << " : " <<  p[nums.size()-1]-p[i] << endl;
            if (p[i]-nums[i] == p[nums.size()-1]-p[i]) return j;
            j++;
        }
        
        return -1;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;

    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            nums.push_back(atoi(argv[i]));
        }
    }

    cout << s.pivotIndex(nums) << endl;
    
    return 0;
}
