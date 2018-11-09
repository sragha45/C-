#include <bits/stdc++.h>
using namespace std;

int v, p[9];

string my_max(string a, string b) {
    if(a.length() != b.length()) {
        if(a.length() > b.length()) 
            return a;
        else 
            return b;
    }
    else {
        for(int i = 0; i < a.length(); i++) {
            if(a[i] < b[i]) {
                return b;
            }
            if(a[i] > b[i]) {
                return a;
            }
        }
        return a;
    }
}

int main() {
    int v;
    cin >> v;
    for(int i = 0; i < 9; i++) {
        cin >> p[i];
    }
    
    vector<string> dp(123456);

    for(int i = 1; i <= v; i++) {    
        dp[0] = "";
        for(int j = 0; j < 9; j++) {
            if(i - p[j] >= 0) {
                char c = (char) j + '1';
              //  cerr << "Value: " << i << " Char: " << c << endl;
              //  cerr << "Old: " << dp[i] << ' ' << "New: " << string(dp[i - p[j]] + c) << endl;
                dp[i] = my_max(dp[i], (dp[i - p[j]] + c));
            }
        }
    }
    if(dp[v] == "") {
        cout << -1;
    }
    else
        cout << dp[v];
    
}
