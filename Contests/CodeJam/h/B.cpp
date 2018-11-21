#include <bits/stdc++.h>
using namespace std;

int a[5234567];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    int lt = (n + 1) / 2, left = 0;
    int sum = 0;
    for(int i = 0; i < lt; i++) {
        sum += a[i];
    }
    int ans = sum;
    for(int i = lt; i < n; i++) {
        sum -= a[left];
        sum += a[i];
        ans = max(ans, sum);
        left++;
    }
    cout << ans;
}

int main() {
    int tt;
    cin >> tt;
    for(int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
