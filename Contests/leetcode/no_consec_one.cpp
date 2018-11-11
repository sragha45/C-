// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

string to_binary(int n) {
    string res;

    while(n) {
        res += (char)('0' + n % 2);
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

string a;
int dp[33][2][2];

int solve(int pos, bool prev_one, bool pref) {

    if(pos == a.length()) return 1;

    int ret = dp[pos][prev_one][pref];
    if(ret != -1) return ret;

    ret = 0;
    int c = a[pos] - '0';
    
    for(int i = 0; i < 2; i++) {
        int c = a[pos] - '0';
        if(prev_one and i == 1) continue;
        if(c == 0 and pref == 1 and i == 1) continue;
        prev_one |= (i == 1);
        ret += solve(pos + 1, prev_one and (i == 1), pref and c == i);
    }

    return ret;
} 

int main() {
    int n;
    cin >> n;
    a = to_binary(n);
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 1);
}
