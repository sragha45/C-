#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int b[s.length() + 1];
    int i = 0, j = -1; b[0] = -1; 
    while(i < s.length()) {
        while(j >= 0 and s[i] != s[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
    int ans = 0;
    int idx = 0;
    for(int i: b) {
        cout << i << ' ';
    }
    cout << endl;
    for(int i = 2; i < s.length() + 1; i++) {
        if(b[i] > b[i - 1]) {
            idx = i;
            break;
        }
            
    }
    for(int i = 0; i <= idx; i++) {
        cout << s[i];
    }
    //cout << ans;
}
