#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> n >> s;
    int ans = 0;
    while(s > 0) {
        if(s / n != 0) {
            ans += (s / n);
            s %= n;
        }
        else n--;
    }
    cout << ans;
}
