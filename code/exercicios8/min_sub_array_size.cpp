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
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, j, dif;
        vector<int> p, res;

        p.push_back(0);

        for_each(nums.begin(), nums.end(), [&p](auto e) {
            p.push_back(p.back()+e);
        });

        print_each(p.begin(), p.end());

        for (i = 0; i < p.size(); i++) {
            for (j = i+1; j < p.size(); j++) {
                dif = p[j]-p[i];

                if (dif >= target) {
                    res.push_back(j-i);
                    break;
                }
            }
        }

        print_each(res.begin(), res.end());

        return res.empty() ? 0 : *min_element(res.begin(), res.end());
    }
};

int main(int argc, char const *argv[])
{
    int target, n;
    vector<int> nums;
    Solution s;

    target = atoi(argv[1]);
    stringstream ss(argv[2]);

    while (ss >> n) {
        nums.push_back(n);
        if (ss.peek() == ',') ss.ignore();
    }

    cout << s.minSubArrayLen(target, nums) << endl;

    return 0;
}
