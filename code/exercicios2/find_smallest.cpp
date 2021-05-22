#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        
        for (auto it = letters.begin(); it < letters.end(); it++) {
            
            if (*it > target) {
                return *it;
            }
        }
        
        return letters[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<char> letters{'c','f','j'};
    char target = 'a';
    Solution s;

    cout << s.nextGreatestLetter(letters, target) << endl;

    return 0;
}
