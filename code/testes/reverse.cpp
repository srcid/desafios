#include <bits/stdc++.h>

using namespace std;

long int reverse(long int x) {
    long int i = 1,
             res;
    stack<int> s;

    do {
        res = x % 10;
        s.push(res);
    } while ((x /= 10));
    
    res = 0;

    while (!s.empty()) {
        res += s.top() * i;
        i *= 10;
        s.pop();
    }

    return res;
}

int main(int argc, char const *argv[])
{
    cout << reverse(6156165) << endl;
    cout << reverse(1534236469) << endl;
    return 0;
}
