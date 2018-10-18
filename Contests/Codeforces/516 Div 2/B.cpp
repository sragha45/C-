#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 0; i < 31; i++) {
		// if((1 << i) > n) break;
		// cout << i << ' ' << (n & (1 << i)) << endl;
		if((n & (1 << i)) > 0) {
			ans *= 2;
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}

