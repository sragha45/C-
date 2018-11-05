#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + m);
    bool b[n + m];

    for(int i = 0; i < n + m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n + m; i++) {
        cin >> b[i];
    }

    vector<pair<int, int> > t, p;
    int pc = 0, tc = 0;
    for(int i = 0; i < n + m; i++) {
        if(b[i] == 1) {
            t.push_back({a[i], tc++});
        }
        else {
            p.push_back({a[i], pc++});
        }
    }

    sort(t.begin(), t.end());
    vector<int> ans(m, 0);

    for(pair<int, int> x: p) {
        auto it = lower_bound(t.begin(), t.end(), x);
        if(it == t.end()) {
            --it;
            ans[(*it).second]++;
//            cout << (*it).first << ' ' << (*it).second << " Size : " << t.size() << endl;
        }
        else if(it == t.begin()) {
            ans[(*(t.begin())).second]++;
        }
        else {
            int d = abs((*it).first - x.first);
            int d1 = abs(((*(it - 1)).first) - x.first);
            if(d1 <= d) {
                ans[(*(it - 1)).second] ++;
            }
            else {
                ans[(*it).second]++;
            }
        }
    }

    for(int i : ans) {
        cout << i << ' ';
    }
        
}

