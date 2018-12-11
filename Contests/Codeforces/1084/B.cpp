#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    long long int a[n + 1];
    long long mn = 1e17;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    long long got = 0;
    for(int i = 0; i < n; i++) {
        got += a[i] - mn;
    }
    if(got >= x) cout << mn << endl;
    else {
        x -= got;
        //cerr << x << endl;
        got = mn * n;
        got -= x;
        //cerr << got << endl;
        if(got < 0) {
            cout << -1 << endl;
        }
        else {
            got /= n;
            cout << got << endl;
        }
    }
}


