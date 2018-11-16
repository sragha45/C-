#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, k;
    cin >> a >> b >> k;
    if(k % 2 == 0) {
        cout << (k / 2) * (a - b) << endl;
    }
    else {
        cout << (k / 2) * (a - b) + (a) << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();
}
