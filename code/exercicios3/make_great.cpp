#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {        
        string res;
        auto i = s.begin();
        
        res.push_back(*i++);

        while (i < s.end()) {

            if (isupper(res.back()) && islower(*i)) {

                if (tolower(res.back())==*i) {
                    res.pop_back();
                    i=s.erase(i);
                    continue;
                }

            } else if (islower(res.back()) && isupper(*i)) {
                
                if (toupper(res.back())==*i) {
                    res.pop_back();
                    i=s.erase(i);
                    continue;
                }

            }

            res.push_back(*i++);

        }

        return res;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.makeGood("abBAcC") << endl;
    cout << s.makeGood("leEeetcode") << endl;
    cout << s.makeGood("mC") << endl;
    cout << s.makeGood("Hvh") << endl;
    cout << s.makeGood("Pp") << endl;
    cout << s.makeGood("kkdsFuqUfSDKK") << endl;

    return 0;
}
