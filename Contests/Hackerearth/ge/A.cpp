#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
    int l = 0, r = s.length() - 1;
    while(l <= r) {
        if(s[l] != s[r]) {
            return false;
        }
        l++, r--;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    bool ok = false;
    for(int i = 0; i < n; i++) {
        ok |= palindrome(s);
        s = s[1] + s.substr(2) + s[0];
    }
    if(ok == true) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
