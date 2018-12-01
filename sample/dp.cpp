#include <bits/stdc++.h>
using namespace std;

int dp[52][102][102];
int a[102], b[102];
int n;

int solve(int pos, int cnt, int rem_day) {
//    cout << pos << ' ' << cnt << ' ' << rem_day << endl;
    if(rem_day < 0) return 0;
    if(pos == n - 1 or rem_day == 0) return (a[pos] + cnt) * b[pos];
    int &ret = dp[pos][cnt][rem_day];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i = 0; i <= rem_day; i++) {
        if(a[pos] + cnt >= i) {
//            cout << pos << ' ' << cnt << ' ' << rem_day << ' ';
//            cout << b[pos] * (a[pos] - i + cnt) << endl;
            ret = max(ret, 
                      b[pos] * (a[pos] - i + cnt) + solve(pos + 1, i, rem_day - i));
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    memset(dp, -1, sizeof dp);
    int days;
    cin >> days;
    cout << solve(0, 0, days);
}
