#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, h;

const int MAXN = 123456;



int main() {

    cin >> n >> h;
    //cout << n << endl;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        h -= a[i];
        if(h < 0) break;
        cnt++;
    }
    cout << cnt - (h > 0);
	return 0;
}
