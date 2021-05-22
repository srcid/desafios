/***
 *  ESTÁ ERRADA  
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void print(int x) {
    cout << "| " << x << " | ";
} 

template<class InputIterator>
int prefix_sum_until_(InputIterator first, InputIterator last, int max) {
    int tmp,
        overflow = 0;
    
    while (first != last) {
        tmp = *first + *(first++ + 1);
        
        if (tmp > max) {
            overflow++;
            continue;
        } else if (tmp == max) {
            overflow++;
        }
        
        *first = tmp;
    }

    return overflow;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight = ceil(accumulate(weights.begin(), weights.end(), 0) / days);

        for (int w : weights) {
            if (w > min_weight) {
                min_weight = w;
            }
        }
        
        while (true) {
            vector<int> acc(weights);
            int overflow = prefix_sum_until_(acc.begin(), acc.end(), min_weight);

            for_each(acc.begin(), acc.end(),print);
            cout << " --- " << overflow << endl;

            if (overflow <= days) {
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

    Solution s;

    cout << s.shipWithinDays(w, d) << endl;
    cout << s.shipWithinDays(w2, d2) << endl;
    cout << s.shipWithinDays(w3, d3) << endl;
    
    return 0;
}
