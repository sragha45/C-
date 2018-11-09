#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int k;

int dp[34][120][120];

void process(int x) {
    v.clear();
    while(x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
}

int f(int pos, bool prefix, int sum, int num) {
    int &r = dp[pos][sum][num];

    if(prefix == 1 and r != -1) return r;
    if(pos == v.size()) {
        return sum % k == 0 and num % k == 0;
    }
    
    r = 0;
    if(prefix == 1) {
        for(int i = 0; i < 10; i++) {
            r += f(pos + 1, prefix, (sum + i) % k, (i + num * 10) % k);
        }
    }
    else {
        for(int i = 0; i < v[pos]; i++) {
            r += f(pos + 1, 1, (sum + i) % k, (i + num * 10) % k);
        }
        r += f(pos + 1, 0, (sum + v[pos]) % k, (v[pos] + (num * 10)) % k);
    }
    return r;
}

void solve(int c) {
    int l, r;
    cin >> l >> r >> k;
    
    memset(dp, -1, sizeof dp);
    process(r);
    int ans = f(0, 0, 0, 0);

    memset(dp, -1, sizeof dp);
    process(l - 1);

    cout << "Case " << c << ": " << ans - f(0, 0, 0, 0) << endl;
}

int main() {
    int tt;
    cin >> tt;
    int i = 1;
    while(tt--) {
    //    memset(dp, -1, sizeof dp);
        solve(i);
        i++;
    }
}
