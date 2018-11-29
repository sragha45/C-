#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int mx = 1e5;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    bool ok = true;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            continue;
        }
        else {
            ok = false;
        }
    }

    if(ok) {
        cout << 0 << endl;
        return 0;
    }
    cout << n + 1 << endl;
    int sum = 0;
    for(int i = n - 1, j = 1; i >= 0; i--, j++) {
        int value = mx - ((sum + a[i]) % mx);
        value += mx - j;
        cout << 1 << ' ' << i + 1 << ' ' << value << endl;
        sum += value;
        a[i] += sum;
    }
    cout << 2 << ' ' << n  << ' ' << mx << endl;
    return 0;
    for(int i = 0; i < n; i++) {
        cout << a[i] % mx << ' ';
    }
}
