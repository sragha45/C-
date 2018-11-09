#include <bits/stdc++.h>
using namespace std;

int n;
int a[123456];

int dp[123456][2][200];

int solve(int pos, bool sat, int num) {
    int &r = dp[pos][sat][num];

    if(r != -1) return r;
    if(pos == n and sat) return 1;

    r = 0;
    for(int i = 0; i <= 200; i++) {


}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve();
}
