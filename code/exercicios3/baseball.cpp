#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        
        for (string op : ops) {
            
            if (op == "+") {
                res.push_back(*(res.end()-1) + *(res.end()-2));
            } else if (op == "D") {
                res.push_back(2*res.back());
            } else if (op == "C") {
                res.pop_back();
            } else {
                res.push_back(stoi(op));
            }
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};