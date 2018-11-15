#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = -1;  
    int same = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            same = false;
        }
    }
    if(same) {
        cout << s.substr(0, s.length() - 1);
        return 0;
    }
    for(int i = 1; i < n; i++) {
        if(s[i] < s[i - 1]) {
            idx = i - 1;
            break;
        }
    }
    if(idx != -1) {
        for(int i = 0; i < n; i++) {
            if(idx == i) continue;
            cout << s[i];
        }
    }
    else {
        cout << s;
    }
}
