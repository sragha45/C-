#include <bits/stdc++.h>
using namespace std;

int a[1234567];

/*int solve(int direction) {
    int done[n];
    for(int i = 0; i < n; i++) {
        done[i] = 0;
    }
    if(direction == 0) {
        int mx = a[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > mx) {
                ans += mx;
                mx = a[i];
                done[i] = 1;
            }
        }
    }
    else {
        int mx = a[0];
        int ans = 0;
    }
}
*/
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    long long int sum = 0;
//    int done[n];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        //done[i] = 0;
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    cout << sum - max(mx, n);
    return 0;
/*
    int mx = a[0];
    int ans = 0;
    set<int> seen;
    seen.insert(a[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] > mx) {
            ans += mx;
            mx = a[i];
  //          done[i] = 1;
        }
        else {
            ans += a[i] - 1;
            if(mx != a[i])
            ans += seen.count(a[i]);
        }
        seen.insert(a[i]);
    }
    seen.clear();
    mx = a[n - 1];
    int res = ans;
    ans = 0;
    seen.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] > mx) {
            ans += mx;
            mx = a[i];
            }
        else {
            ans += a[i] - 1;
            if(mx != a[i])
            ans += seen.count(a[i]);
        }
        seen.insert(a[i]);
        
    }
  //  cout << ans << endl;
 for(int i = 0; i < n; i++) {
        if(!done[i]) {
            ans += a[i] - 1;
        }
    }
    cout << max(res, ans);
    */
}
