#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int diff = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i == 0) diff += a[i];
		else diff += abs(a[i - 1] - a[i]);
	}
	int res = diff, temp = diff;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			diff = temp;
			if(i == 0) {
				diff -= a[0];
				diff -= abs(a[1] - a[0]);
				diff += a[j];
				if(j - i == 1) diff += abs(a[j] - a[i]);
				else diff += abs(a[j] - a[1]);
				// cout << i << ' ' << j << ' ' << diff << endl;
			}
			else {
				diff -= abs(a[i - 1] - a[i]);
				diff -= abs(a[i] - a[i + 1]);
				diff += abs(a[j] - a[i - 1]);
				if(j - i == 1) diff += abs(a[j] - a[i]);
				else diff += abs(a[j] - a[i + 1]);
			}
			if(j - i == 1) {
				if(j != n - 1) {
					diff -= abs(a[j + 1] - a[j]);
					diff += abs(a[i] - a[j + 1]);
				}
				
			}
			else {
				diff -= abs(a[j - 1] - a[j]);
				if(j != n - 1)
					diff -= abs(a[j] - a[j + 1]);
				diff += abs(a[j - 1] - a[i]);
				if(j != n - 1)
					diff += abs(a[i] - a[j + 1]);
			}
			// cout << i << ' ' << j << ' ' << diff << endl;	
			res = min(diff, res);
		}
	}
	cout << res << endl;
}