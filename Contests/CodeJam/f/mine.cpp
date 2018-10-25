#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(ll a, ll b, ll c) {
	if(a * b == c or b * c == a or c * a == b) return true;
	return false;
}

int solve() {
	int n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				if(ok(a[i], a[j], a[k])) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {	
	int tt;
	cin >> tt;
	for(int i = 1; i <= tt; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}