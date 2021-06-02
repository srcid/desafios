#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int i = 0, dif = 0;
        
        for (char c : s) {
            switch (c)
            {
            case '(':
                i++;
                break;
            
            case ')':
                i--;
                if (i < 0) {
                    i = 0;
                    dif++;
                }
                break;
            }
        }
        
        return dif+i;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "(((()))((";
    cout << s.minAddToMakeValid(str) << endl;
    return 0;
}
