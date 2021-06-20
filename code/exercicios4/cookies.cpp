#include <bits/stdc++.h>

#define all(arr) arr.begin(), arr.end()

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> greedy(all(g)),
                            cookies(all(s));
        int matches = 0,
            range = min(g.size(), s.size()),
            i;

        while (!(cookies.empty() || greedy.empty())) {
            if (cookies.top() >= greedy.top()) {
                matches++;
                cookies.pop();
            }
            greedy.pop();
        }

        return matches;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> g1{1,2},   // fome das crianças
                s1{1,2,3}, // tamanho dos cookis
                g2{1,2,3},
                s2{1,1};

    Solution s;

    cout << s.findContentChildren(g1, s1) << endl;
    cout << s.findContentChildren(g2, s2) << endl;
    
    return 0;
}
