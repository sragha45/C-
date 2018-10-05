#include<stdio.h>  
#include <bits/stdc++.h>
#include<stdlib.h>

using namespace std;


typedef long long ll;

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


const ll INF = 2e9;

int k;

int prev(int i, int k) {
    if(i == 0) return k - 1;
    else return i - 1;
}

int main() {
    int n;
    cin >> n >> k;
    int dp[n + 1][k];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            if(dp[i - 1][prev(j, k)] != -1) {
                if(dp[i][j] == -1) {
                    dp[i][j] = 1 + dp[i - 1][prev(j, k)] ;
                }
                else dp[i][j] = min(dp[i][j], 1 + dp[i - 1][prev(j, k)]);
            }
            if(i > 1 and dp[i - 2][prev(j, k)] != -1) {
                if(dp[i][j] == -1) {
                    dp[i][j] = 1 + dp[i - 2][prev(j, k)]  ;
                }
                else dp[i][j] = min(dp[i][j], 1 + dp[i - 2][prev(j, k)]);
            }
        }
    }
    cout << dp[n][0];
}
