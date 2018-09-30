#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    freopen("input.txt", "r", stdin);
    
    int n, m, d;
    cin >> n >> m >> d; 
    d++;

    pair<int, int> a[n]; 
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    set<pair<int, int> > intervals(a, a + n);
    int days = 0;
    int ans[n];

    while(!intervals.empty()) {
        days++;
        pair<int, int> x = *intervals.begin();
        pair<int, int> k = x;
        while(intervals.lower_bound(make_pair(k.first + d, -1)) != intervals.end()) {
            k = *intervals.lower_bound(make_pair(k.first + d, -1));
        //    cerr << k.first << ' ';
            ans[k.second] = days;
            intervals.erase(k);
        }
        //cerr << endl;
        intervals.erase(x);
        ans[x.second] = days;
    }

    cout << days << endl;
    for(int i: ans) {
        cout << i << ' ';
    }
    return 0;
}
