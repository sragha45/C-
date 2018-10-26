#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	set<int> done;
	int ptr = 0, prev = 0;
	for(int i = 0; i < n; i++) {
		int x = b[i];
		if(done.count(x) == 1) {
			cout << 0 << ' ';
			continue;
		}
		while(a[ptr] != x) {
			done.insert(a[ptr]);
			ptr++;
		}
		done.insert(a[ptr]);
		ptr++;
		cout << ptr - prev << ' ';
		prev = ptr;
	}	
}

