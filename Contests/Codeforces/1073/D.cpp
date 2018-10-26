#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; long long k;
	cin >> n >> k;
	queue<long long int> q;
	int a[n];
	long long sum = 0;
	for(int i = 0; i < n; i++) {
	       	cin >> a[i];
		if(a[i] > k) continue;
		q.push(a[i]);
		sum += a[i];
	}
	long long ans = 0;
	if(sum != 0) {
		ans = (k / sum) * q.size();
		k -= (k / sum) * sum;
	}
	long long prev = 0;
	while(!q.empty() and k > 0) {
		sum = 0;
		int sz = q.size();
		for(int i = 0; i < sz; i++) {
			long long elt = q.front();
			if(elt > k) {
				q.pop();
			}
			else {
				q.pop();
				if(k - elt >= 0) {
					q.push(elt);
					k -= elt;
					ans++;
					sum += elt;
				}
			}
		}
		if(sum == 0) break;
		ans += k / sum * q.size();
		k -= (k / sum) * sum;
	
	
	}
	cout << ans << endl;
}
