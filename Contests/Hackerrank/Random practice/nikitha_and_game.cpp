#include <bits/stdc++.h>
using namespace std;

int dp[2050][2050];

long long p[2050];

void process(int *a, int n) {
    p[0] = a[0];
    for(int i = 1; i < n; i++) {
        p[i] = a[i] + p[i - 1];
    }
}


long long get_sum(int l, int r) {
    return p[r] - p[l - 1];
}

int f(int start, int end, int *a) {
    if(dp[start][end] != -1) {
        return dp[start][end];
    }
    long long ans = 0, sum = 0;
    long long target;
    sum = get_sum(start, end);
    if(sum % 2 != 0 or start == end) {
        dp[start][end] = 0;
        return 0;
    }
    target = sum / 2LL;
    sum = 0;
    for(int i = start; i < end; i++) {
        sum += a[i];
        if(sum == target) {
            ans = max(f(start, i, a), f(i + 1, end, a)) + 1;
        }
    }
    dp[start][end] = ans;
    return ans;
}


void solve() {
    int n;
    cin >> n;
    int a[n];
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    process(a, n);
    cout << f(0, n - 1, a) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
