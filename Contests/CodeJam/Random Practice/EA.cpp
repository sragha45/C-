#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a, a + n);
    int ptr = 0;
    int day = 0;
    int ans = 0;
    int consumed_today = 0;
    while(ptr < n) {
    	consumed_today = 0;

    	while(ptr < n and a[ptr] < day - 1) ptr++;
    	while(ptr < n and consumed_today < k) {    		
    		if(a[ptr] > day) {
    			ptr++;
				consumed_today++;
				ans++;
    		}
    		else{
    			ptr++;
    		}	
    	}
    	// cout << day << ' ' << consumed_today << ' ' << ptr << ' ' << ans << endl;
    	day++;
    }
    return ans;
}

int main() {	
	int tt;
	cin >> tt;
	for(int i = 1; i <= tt; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}

}