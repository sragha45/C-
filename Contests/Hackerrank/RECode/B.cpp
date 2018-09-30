#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	int n; 
	cin >> n;
	pair<int, int> a[n];
	int x = 0 , y = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if(ans < a[i].first + a[i].second) {
			ans = a[i].first + a[i].second;
			x = a[i].first;
			y = a[i].second;
		}
	}
	
	cout << ceil(ans);  
}