#include <bits/stdc++.h>
using namespace std;

long long int n, s;
string hi, lo;

long long dp[20][200][2][2];

long long solve(int pos, int sum, int hipref, int lowpref) {
//    cout << hipref << ' ' << lowpref << endl;
    if(sum < 0) return 0;

    if(pos == lo.length()) {
        return sum == 0;
    }
    long long &res = dp[pos][sum][hipref][lowpref];
    if(res != -1) {
        return res;
    }
    res = 0;
    for(int i = 0; i < 10; i++) {
        int curHi = hi[pos] - '0';
        int curLo = lo[pos] - '0';
        
        if(hipref == 0 and i > curHi) continue;
        if(lowpref == 0 and i < curLo) continue;
    
        res += solve(pos + 1, sum - i, hipref | (i < curHi), lowpref | (i > curLo));
    }
    return res;
}


int main() {
    cin >> n >> s;

    hi = to_string(n);
    long long cnt = 0;
    
    for(int sum = 0; sum <= 170; sum++) {
        memset(dp, -1, sizeof dp);
        lo = to_string(s + sum);
        if(s + sum > n) break;
        while(hi.length() > lo.length()) {
            lo = "0" + lo;
        }
        //cout << lo << endl;
        cnt += solve(0, sum, 0, 0);
    }
    cout << cnt;
}

