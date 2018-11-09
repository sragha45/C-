#include <bits/stdc++.h>
using namespace std;

string s, ans[10];
bool dp[104][8];

bool solve() {
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < s.length(); i++) {
        if(i > 0) {
            for(int j = 0; j < 8; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for(int j = 0; j < 8; j++) {
                if(dp[i - 1][j]) {
                    int new_mod = ((j * 10) + s[i] - '0') % 8;
                    if(dp[i][new_mod] == false) {
                        dp[i][new_mod] = true;
                        ans[new_mod] = ans[j] + s[i];
                    }
                }
            }
        }
        int c = s[i] - '0';
        if(dp[i][c % 8] == false) {
            dp[i][c % 8] = true;
            ans[c % 8] += s[i];
        }
        
    }
    return dp[s.length() - 1][0];
}

int main() {
    cin >> s;

    if(solve()) {
        cout << "YES\n" << ans[0];
    }
    else {
        cout << "NO" << endl;
    }
}
