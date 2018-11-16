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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(a[i] == 0 and a[i - 1] == 1 and a[i + 1] == 1) {
            ans++;
            a[i + 1] = 0;
        }
    }
    cout << ans;
}
