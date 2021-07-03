#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_frq, frq;
        int length = 0;
        
        for (char c : chars) {
            chars_frq[c]++;
        }
        
        for (string word : words) {
            frq = chars_frq;
            
            for (char c : word) {
                if (!frq[c]) {
                    goto donotcount;
                }
                frq[c]--;
            }
            
            length += word.length();
            
            donotcount:;
        }
        
        return length;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words{"cat","bt","hat","tree"};
    string chars = "atach";
    cout << s.countCharacters(words, chars) << endl;

    return 0;
}
