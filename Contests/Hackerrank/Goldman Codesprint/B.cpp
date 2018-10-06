#include <bits/stdc++.h>
using namespace std;

int n, m;

void process(string &s, string &p, vector<int> &a) {
	m = p.length(), n = s.length();
	int i = 0, j = -1, b[m + 1];

	b[0] = -1;
	while(i < m) {
		while(j >= 0 and p[i] != p[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}

	i = 0, j = 0;
	while(i < n) {
		while(j >= 0 and s[i] != p[j]) j = b[j];
		i++; j++;
		if(j == m) {
			a.push_back(i - j);
			j = b[j];
		}
	}
}

void find_in(vector<int> &a, int x) {
	for(int i = 0; i < a.size(); i++) {
		int value = a[i];
		// cout << a[i] << ' ' << x << ' ' << a[i] + m << endl;
		if(x >= value and x < value + m) {
			a.erase(a.begin() + i);
			i--;
			// return;
		}
	}
}

void solve() {
	string s, p;
	cin >> s >> p;
	vector<int> a;
	process(s, p, a);
	int q;
	cin >> q;
	
	int ans = -1;
	vector<pair<int, char> > queries(q);
	for(int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}
	
	if(a.size() != 0) {
		for(int i = 0; i < q; i++) {
			int idx = queries[i].first; char ch = queries[i].second;
			if(ch == s[idx]) continue;
			find_in(a, idx);
			if(ans == -1 and a.size() == 0) {
				ans = i + 1;
				break;
			}	
		}
		cout << ans << endl;
	}
	else
		cout << 0 << endl;
	
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
}