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

int solve(int pos, int k, int c) {
    long long &ret = dp[pos][k];
    if(ret != -1)  {
//        cout << pos << ' ' << k << endl;
        return ret;
    }
    if(pos > n) {
        return 0;
    }
    if(k == 0) {
        if(pos >= n) return 0;
        return c + is_palindrome(pos, n);
    }
//     cout << pos << ' ' << k << ' ' << c << " : " << endl;
    ret = 0;
    for(int i = pos + 1; i <= n; i++) {
        bool is_palin = is_palindrome(pos, i);
        ret = (ret + solve(i, k - 1, is_palin + c)) % mod;
        cout << "From " << pos << " to " << i - 1 << " with " << k  << " is " << solve(i, k - 1, is_palin + c)  << endl;
    }
//    cout << pos << ' ' << k << ' ' << ret << endl;
    return ret % mod;
}


int main() {
    cin >> n >> k >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0, k, 0);

    return 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << dp[i][j] << " \n"[j == k];
        }
    }
}
