#include <bits/stdc++.h>
using namespace std;

const int md = 998244353;

inline int mul(int a, int b) {
	  return (int) ((long long) a * b % md);
}

inline void add(int &a, int b) {
	a += b;
	if (a >= md)
		a -= md;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0, prev = 0;
	for(int i = 1; i < n - 1; i++) {
		if(a[i] == -1) {
			if(prev != 0) {
				ans = add(ans, mul(prev, (200 - min(a[i - 1], a[i + 1]))));
				prev = ans;
			}
			else {
				ans  = add(ans, 200 - min(a[i - 1], a[i + 1]));
			        prev = ans;
			}
		}
	}
	if(a[0] == -1) {
		if(a[1] != -1) {
			ans = add(ans, a[1]);
		}
					
