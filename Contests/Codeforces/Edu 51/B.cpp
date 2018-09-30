#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool smaller(char c) {
	return (c >= 'a' and c <= 'z');
}

bool u(char c) {
	return (c >= 'A' and c <= 'Z');
}

bool n(char c) {
	return (c >= '0' and c <= '9');
}

void solve() {
	string s;
	cin >> s;
	int small = 0, upper = 0, number = 0;
	for(char c: s) {
		small += smaller(c);
		upper += u(c);
		number += n(c);
	}
	if(small and upper and number) cout << s;
	else {
		if(upper > 1 and small > 1 and number == 0) cout << '1' << s.substr(1);
		else if(small > 1 and number > 1 and upper == 0) cout << 'A' << s.substr(1);
		else if(upper > 1 and number > 1 and small == 0) cout << 'a' << s.substr(1); 
		else if(upper == 0 and small == 0 and number > 1) cout << "Ab" << s.substr(2);
		else if(upper == 0 and number == 0 and small > 1) cout << "A9" << s.substr(2);
		else if(number == 0 and small == 0 and upper > 1) cout << "a9" << s.substr(2);
	}
	cout << endl;
}



int main() {
	int tt; cin >> tt;
	while(tt--) solve();
}