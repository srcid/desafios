#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        auto first = s.begin();
        int i;
        string res;

        while (first != s.end()) {
            i = 0;
            auto last = first;
            
            do {
                if (*last == '(') {
                    i++;
                } else {
                    i--;
                }
                last++;
            } while (i);

            res.append(first+1, last-1);
            first = last;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string arr = "(()())(())";
    cout << s.removeOuterParentheses(arr) << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;
    return 0;
}
