#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

long long dp[5002][5002];

int mod = 1e9 + 7;

bool is_palindrome(int start, int end) {
    end--;
    for(int i = start; i <= end; i++) {
        cout << s[i];
    }
    cout << endl;
    while(start <= end) {
        if(s[start] != s[end]) return false;
        start++, end--;
    }
    return true;
}

long long ans = 0;

int solve(int pos, int k) {
    long long &ret = dp[pos][k];
    if(ret != -1)  {
//        cout << pos << ' ' << k << endl;
        return ret;
    }
    if(pos > n) {
        return 0;
    }
    if(k <= 0) {
        bool is_palin = is_palindrome(pos, n);
        cout << "From " << pos << " to " << n << " with " << k << " is " << is_palin << endl;
        return ret = is_palin;
    }

//     cout << pos << ' ' << k << ' ' << c << " : " << endl;
    ret = 0;
    for(int i = pos + 1; i < n; i++) {

        ret = (is_palindrome(pos, i) + solve(i, k - 1)) % mod;
        ans = (ans + ret) % mod;
        cout << "From " << pos << " to " << i - 1 << " with " << k  << " is " << ret  << endl;
    }
//    cout << pos << ' ' << k << ' ' << ret << endl;
    return ret % mod;
}


int main() {
    cin >> n >> k >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0, k) << endl;
    cout << ans << endl;;

    

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            dp[j][i] = max(0LL, dp[j][i]);
            cout << dp[j][i] << " \n"[j == n];
        }
    }
}
