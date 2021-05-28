#include <bits/stdc++.h>

using namespace std;

template<class InputIterator, class T>
int prefix_sum_until(InputIterator first, InputIterator last, T max) {
    T acc = 0;
    int count = 1;
    
    while (++first != last) {
        acc = *first + *(first - 1);
        
        if (acc > max) {
            count++;
            continue;
        } else if (acc == max && first + 1 != last) {
            count++;
            *first = acc;
            first++;
        } else {
            *first = acc;
        }
    }

    return count;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight = max(
            (int)(ceil(accumulate(weights.begin(), weights.end(), 0) / days)),
            *max_element(weights.begin(), weights.end())
        );

        while (true) {
            vector<int> acc(weights);
            int batchs_count = prefix_sum_until(acc.begin(), acc.end(), min_weight);

            if (batchs_count <= days) {
                return min_weight;
            } else {
                min_weight++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> w{1,2,3,1,1};
    int d = 4;   
    vector<int> w2{3,2,2,4,1,4};
    int d2 = 3;
    vector<int> w3{1,2,3,4,5,6,7,8,9,10};
    int d3 = 5;
    vector<int> w4{1,2,3,4,5,6,7,8,9,10};
    int d4 = 1;

    Solution s;

    cout << s.shipWithinDays(w, d) << endl;
    cout << s.shipWithinDays(w2, d2) << endl;
    cout << s.shipWithinDays(w3, d3) << endl;
    cout << s.shipWithinDays(w4, d4) << endl;
    
    return 0;
}
