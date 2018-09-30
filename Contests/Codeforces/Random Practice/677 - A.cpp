//http://codeforces.com/problemset/problem/677/A

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  //  freopen("input.txt", "r", stdin);
    
    int n, h; cin >> n >> h;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += 1 + (x > h);
    }

    cout << ans << endl;

    return 0;
}
