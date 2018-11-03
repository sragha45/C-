#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n + 2];
    for(int i = 0; i <= n + 1; i++) {
        dp[i] = 2e9;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 1; i * i <= n; i++) {
        int val = i * i;
        for(int j = val; j <= n; j++) {
            dp[j] = min(dp[j - val] + 1, dp[j]);
        }
    }
    cout << dp[n];
}
