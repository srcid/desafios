#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int PICK = 6;

int guess(int n) {

    if (n > PICK) {
        return 1;
    } else if (n < PICK) {
        return -1; 
    } else {
        return 0;
    }
    
}

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        int res,
            beg = 1,
            end = n,
            hint = end/2;

        /* Se res for 0 o while será quebrado */
        while ( (res = guess(hint)) ) {
            // hint é maior
            if (res == 1) {
                end = hint;
            // hint é menor
            } else {
                beg = hint;
            }
            hint = (end + beg)/2;

        }
        
        return hint;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << "N: " << N << " - PICK: " << PICK << endl;
    int findv = s.guessNumber(N);
    cout << "FIND: " << findv << endl;

    return 0;
}
