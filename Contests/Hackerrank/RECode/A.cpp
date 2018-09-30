#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class dsu {
	vector<int> p, r, q;
	int n;
public:
	dsu(int _n) : n(_n) {
		p.assign(n + 1, 0);
		r.assign(n + 1, 1);
		q.assign(n + 1, 1);
		for(int i = 1; i <= n; i++) {
			cin >> q[i];
			p[i] = i;
		}
	}
	int parent(int x) {
		if(x == p[x]) return x;
		else return p[x] = parent(p[x]);
	}
	bool same(int x, int y) {
		return parent(x) == parent(y);
	}
	void unite(int x, int y) {
		x = parent(x); y = parent(y);
		if(x != y) {
			if(r[x] > r[y]) {
				p[y] = x;
				q[x] += q[y];
				q[y] = 0;
			}
			else {
				p[x] = y;
				q[y] += q[x];
				q[x] = 0;
				if(r[x] == r[y]) r[y]++;
			}
		}
	}
	int get2Max() {
		int mx = 0, mx2 = 0;
		for(int i: q) {
			cout << i << ' ';
			if(i > mx) {
				mx2 = mx;
				mx = i;
			}
			else if(i > mx2) {
				mx2 = i;
			}
		}
		cout << endl;
		return mx + mx2;
	}
};

int main() {
	freopen("input.txt", "r", stdin);

	int n, e;
	cin >> n >> e;
	dsu ds(n);
	for(int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		ds.unite(u, v);
	}
	cout << ds.get2Max();
}