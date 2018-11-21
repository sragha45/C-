#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> seen;
    long long int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += seen[i - x];
        seen[x - i]++;
    }
    cout << ans;
}
