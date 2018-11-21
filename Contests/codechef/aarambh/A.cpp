#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;
        int times = n / k;
        cout << ((times) * (times + 1) / 2) * k << endl;
    }
}
