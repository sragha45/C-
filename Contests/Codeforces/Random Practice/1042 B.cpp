#include <bits/stdc++.h>

using namespace std;

int getValue(string s) {
	map<int, char> values;
	values['A'] = 1;
	values['B'] = 2;
	values['C'] = 4; 
	int value = 0;
	for(char c: s) {
		value += values[c];
	}
	return value;
}

int main() {

	freopen("input.txt", "r", stdin);

	int a[8];

	for(int i = 0; i < 8; i++) {
		a[i] = 2e9;
	}

	int n;
	cin >> n;
	map<int, int> data;
	for(int i = 0; i < n; i++) {
		int x; string s;
		cin >> x >> s;
		sort(s.begin(), s.end());
		int mineral = getValue(s);
		a[mineral] = min(a[mineral], x);
	}
	for(int i = 1; i < 8; i++) {
		for(int j = 1; j < 8; j++) {
			if(a[i] != 2e9 and a[j] != 2e9)
				a[i | j] = min(a[i | j], a[i] + a[j]);
		}
	}
	if(a[7] == 2e9) {
		cout << -1;
	}
	else {
		cout << a[7];
	}

}