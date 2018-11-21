#include <bits/stdc++.h>
using namespace std;

bool ok(string s, vector<string> &taken) {
    for(string cmp: taken) {
        bool yes = true;
        for(int i = 0; i < cmp.length(); i++) {
            if(s[i] != cmp[i]) {
                yes = false;
                break;
            }
        }
        if(yes == true) { 
            taken.push_back(s);
            return true;
        }
    }
    taken.push_back(s);
    return false;
}

void solve() {
    int n, p;
    cin >> n >> p;
    long long total = (1LL << n);
    vector<string> v(p);
    for(int i = 0; i < p; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<string> taken;
    for(string s: v) {
        if(!ok(s, taken)) {
            total -= (1LL << (n - s.length()));
        }
    }
    cout << total;
}

int main() {
    int tt;
    cin >> tt;
    for(int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
