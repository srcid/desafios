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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> p, res;
        int i;
        i=0;

        print_each(arr.begin(), arr.end());
        
        p.push_back(i);
        for_each(arr.begin(), arr.end(),[&p, &i](auto e){
            i ^= e;
            p.push_back(i);
        });

        print_each(p.begin(), p.end());

        for (auto q : queries) {
            res.push_back( (p[q[1]+1]) ^ (p[q[0]]) );
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr{1,3,4,8}, res;
    vector<vector<int>> queries{{0,1},
                                {1,2},
                                {0,3},
                                {3,3}};
    vector<int> arr2{4,8,2,10};
    vector<vector<int>> queries2 = {{2,3},{1,3},{0,0},{0,3}};

    res = s.xorQueries(arr, queries);

    print_each(res.begin(), res.end());

    res = s.xorQueries(arr2, queries2);

    print_each(res.begin(), res.end());

    return 0;
}
