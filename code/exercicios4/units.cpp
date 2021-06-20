#include <bits/stdc++.h>

using namespace std;

template <class T>
void printVector(std::vector<T>& v) {
    std::cout << "[";
    for_each(v.begin()+1, v.end()-1, [](T x){std::cout << x << ", ";});
    std::cout << v.back() << "]";
}

void printMatrix(vector<vector<int>>& m) {
    cout << "[";
    for (auto v : m) {
        printVector(v);
    }
    cout << "]" << endl;
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int in=0, acc=0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){return (a[1]>b[1]);});

        for (auto v : boxTypes) {
            while (v[0]--) {
                in++;
                acc += v[1];

                if (in == truckSize) {
                    goto loopout;
                }
            }
        }

        loopout:

        return acc;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> boxTypes{{1,3},{2,2},{3,1}};
    // int truckSize = 4;
    vector<vector<int>> boxTypes{{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    Solution s;
    cout << s.maximumUnits(boxTypes, truckSize) << endl;

    return 0;
}
