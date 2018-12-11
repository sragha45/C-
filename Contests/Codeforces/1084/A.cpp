#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1e7;
    for(int pos = 1; pos <= n; pos++) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            cout <<  2 * (abs(pos - i) + i - 1) * a[i] << endl;;
            res += 2 * (abs(pos - i) + i - 1) * a[i];
        }
//        cout << res << endl;
        ans = min(ans, res);
    }
    cout << ans << endl;
}
