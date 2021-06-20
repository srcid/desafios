#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<char, int>>::iterator firstNonZero(vector<pair<char, int>>& arr) {
        for (auto i=arr.begin(); i < arr.end(); i++) {
            if ((*i).second != 0) {
                return i;
            }
        }
        return arr.end();
    }

    bool isHappy(string& s) {
        map<char, int> freq;
        
        for (char c : s) {
            freq[c]++;
            
            if (freq[c] == 3) {
                return false;
            }
        }

        return true;
    }

    void printLim(vector<pair<char,int>> arr) {
        cout << '[';
        for_each(arr.begin(), arr.end(), [](pair<char,int> p){cout << '(' << p.first << ',' << p.second << ')';});
        cout << ']' << endl;
    }

    void sortLim(vector<pair<char,int>> arr) {
        sort(arr.begin(), arr.end(), [](pair<char, int> a, pair<char, int> b){
            return (a.second > b.second);
        });
    }

    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<char, int>> letters{{'a',a},{'b',b},{'c',c}};

        while (isHappy(res)) {
            sortLim(letters);
            printLim(letters);
            for (auto p : letters) {
                if (p.second > 1) {
                    res.append(string(p.first,2));
                    p.second -= 2;
                } else {
                    res.push_back(p.first);
                }
            }
        }

        res.pop_back();

        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.longestDiverseString(1,1,7) << endl;
    return 0;
}
