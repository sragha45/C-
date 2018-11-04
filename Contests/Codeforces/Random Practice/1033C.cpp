#include <bits/stdc++.h>
using namespace std;

int a[123456];
int dp[123456][2];
int n;

bool ok(int pos, int i) {
    return a[i] > a[pos];
}

bool f(int pos, bool turn) {
   // cerr << pos << ", "  << turn  << endl;
    if(dp[pos][turn] != -1) {
    //    cerr << "Hit: " << pos << ", " << turn << endl;
        return dp[pos][turn];
    }
    bool win = !turn;

    // backward
    for(int i = pos; i >= 0; i -= a[pos]) {
        if(ok(pos, i)) {
            if(f(i, !turn) == turn) {
                win = turn;
                dp[pos][turn] = win;
                return win;
            }
        }
    }

    //forward
    for(int i = pos; win != turn and i < n; i += a[pos]) {
        if(ok(pos, i)) {
            if(f(i, !turn) == turn) {
                win = turn;
                dp[pos][turn] = win;
                return win;
            }
        }
    }
    dp[pos][turn] = win;
    dp[pos][!turn] = !win;

    return win;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        int ans = f(i, 0);
        if(ans == 0) {
            cout << "A";
        }
        else
            cout << "B";
        //cout << ans << '\n';
    }
}
