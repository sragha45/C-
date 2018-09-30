//http://codeforces.com/problemset/problem/1036/B

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
   // freopen("input.txt", "r", stdin);
    ll a, b;
    cin >> a >> b;
    while(a != 0 and b != 0) {
        if(a >= 2 * b) {
            a %= 2 * b;
        }
        else if(b >= 2 * a) {
            b %= 2 * a;
        }
        else break;
    }
    cout << a << ' ' << b;
    return 0;
}
