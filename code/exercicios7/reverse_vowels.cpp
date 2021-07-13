#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isVowel(char c) {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    
    string reverseVowels(string s) {
        string::iterator i, j;
        i = s.begin();
        j = s.end()-1;
        
        while (i <= j) {
            if (isVowel(*i)) {
                while (!isVowel(*j) && j!=i) j--;
                swap(*i, *j);
                j--;
            }
            i++;
        }
        
        return s;
    }
};