#include <bits/stdc++.h>

using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);

	int n; cin >> n;
	int f[100];
	int a[100];
	memset(f, 0, sizeof f);
	set<int> x, y;
	for(int i = 0; i < n; i++) {
		int q; cin >> q;
		f[q]++;
		a[i] = q;
	}

	string res;
	for(int i = 0; i < n; i++) {
		if(f[ a[i] ] > 1) {
			res += 'A';
		}
		else {
			//cout << a[i] << ' ';
			if(x.size() <= y.size()) {
				//cout << "A: " << a[i] << endl;
				x.insert(a[i]);
				res += 'A';
			}
			else {
				if(x.size() > y.size()) {
					//cout << "B: " << a[i] << endl;
					res += 'B';
					y.insert(a[i]);
				}
			}
		}
	}
	if(x.size() == y.size()) {
		cout << "YES\n" << res;
	}
	else {
		cout << "NO\n";
	}
}