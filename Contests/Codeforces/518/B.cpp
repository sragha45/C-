#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long ans = 0;
	for(long long i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			ans += (n / i == i ? 1 : 2);
		}
	}
	cout << ans << endl;
}
