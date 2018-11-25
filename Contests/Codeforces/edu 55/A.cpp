#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    if(y > n or y < 1) {
        cout << -1 << endl;
        return;
    }
    if(abs(y - x) % d == 0) {
        cout << abs(y - x) / d << endl;
    }
    else {
        if((y - 1) % d == 0) {
             cout << ceil((double)x / d) + ((y - 1) / d) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
    
int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) solve();
}
