#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> k >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[k][n];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 2e9;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != -1)
            dp[0][i] = a[i];
    }
    for(int i = 1; i < k; i++) {
        for(int c = i; c < n; c++) {
            if(a[c] != -1)
            dp[i][c] = min(dp[i - 1][c - i] + a[c], dp[i - 1][c]);
        }
    }
//    for(int i = 0 ; i < k; i++) {
//        for(int j = 0; j < n; j++) {
//            cout << dp[i][j] << " \n"[j == n - 1];
//        }
//    }
    if(dp[k - 1][n - 1] == 2e9) {
        cout << -1 << endl;
    }
    else {
        cout << dp[k - 1][n - 1] << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();
}
