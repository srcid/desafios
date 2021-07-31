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
    int minStartValue(vector<int>& nums) {
        int i;

        i=0;
        for_each(nums.begin(), nums.end(), [&i](auto& e) {
            e += i;
            i = e;
        });

        print_each(nums.begin(), nums.end());

        i = *min_element(nums.begin(), nums.end());

        if (i > 0) return 1;
        else return abs(i)+1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{-3,2,-3,4,2};
    Solution s;

    cout << s.minStartValue(nums) << endl;
    
    return 0;
}