#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void process(string &s, vector<string> &r) {
	int n = s.length();
	string res;
	for(char c: s) {
		res += r[c - '0'];
	}
	s = res;
}

int main() {
	ll n, m, q;
	cin >> n >> m >> q;
	string s;
	cin >> s;
	vector<string> r(10);
	for(int i = 0; i < 10; i++) {
		cin >> r[i];
	}
	while(s.length() <= m) {
		process(s, r);
	}
	cout << s;
}