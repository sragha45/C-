#include <bits/stdc++.h>
using namespace std;

string ans;

void f(int o, int c, int n) {
	if(o == c and o + c == n * 2) {
		cout << ans << endl;
	}
	if(o <= n) {
		ans += '(';
		f(o + 1, c, n);	
	}
	if(c < o) {
		ans += ')';
		f(o, c + 1, n);
	}
	ans = ans.substr(0, ans.length() - 1);
}

int main() {
	int n;
	cin >> n;
	f(0, 0, n);
}

