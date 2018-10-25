#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve() {
	int n;
	cin >> n;
	ll a[n];
	map<ll, vector<int> > f;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]].push_back(i);
	}
	int ans = 0;
	set<vector<int> > seen;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ll prod = a[i] * a[j];
			if(f.find(prod) != f.end()) {
				for(int k: f[prod]) {
					vector<int> thi = {i, j, k};
					sort(thi.begin(), thi.end());
					if(i != k and j != k and seen.count(thi) == 0) {
						for(int x: thi) {
							cout << x << ' ';
						}
						cout << endl;
						seen.insert(thi);
						ans++;
					}
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