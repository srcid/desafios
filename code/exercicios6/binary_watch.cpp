#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ndig(int x) {
        int i = 1;
        while (x /= 10) {
            i++;
        }
        return i;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        const int nleds = 10;
        vector<int> clock;
        vector<string> res;

        for (int i=0; i<nleds; i++) {
            if (turnedOn) {
                turnedOn--;
                clock.push_back(1);
            } else {
                clock.push_back(0);
            }
        }

        sort(clock.begin(), clock.end());


        do {
            for_each(clock.begin(), clock.end(), [](auto s){cout << s << ", ";});
            cout << endl;
            
            int h = clock[0]<<3 | clock[1]<<2 | clock[2]<<1 | clock[3];
            int m = clock[4]<<5 | clock[5]<<4 | clock[6]<<3 | clock[7]<<2 | clock[8]<<1 | clock[9];

            cout << "h: " << h << " m: " << m << endl;

            if (h < 12 && m < 60) {
                if (ndig(m) == 1) {
                    res.push_back(to_string(h) + ":0" + to_string(m));
                } else {
                    res.push_back(to_string(h) + ":" + to_string(m));
                }
            } 

        } while (next_permutation(clock.begin(), clock.end()));

        return res;
    }
};

int main(int argc, char const *argv[])
{
    int turnedOn = atoi(argv[1]);
    
    Solution s;
    auto res = s.readBinaryWatch(turnedOn);

    for_each(res.begin(), res.end(), [](string s){cout << s << ", ";});
    cout << endl;

    return 0;
}
