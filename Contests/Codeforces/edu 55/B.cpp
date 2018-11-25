#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int totalG = 0;
    for(char c: s) {
        totalG += (c == 'G');
    }
    
    int start = 0;
    bool taken = 0;
    int ans = 0;
    int lastS = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'G') {
            totalG--;
            if(totalG == 0) {
                totalG += lastS - start;
                start = i;
            }
        }
        else if(not taken) {
           if(totalG - 1 >= 0) {
                taken = true;
           }
        }
        else {

    cout << ans << endl;
}

