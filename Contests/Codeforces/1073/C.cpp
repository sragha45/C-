#include <bits/stdc++.h>
using namespace std;

int n; string s;
int x, y;

void update(char choice, pair<int, int> &pos, int d) {
    switch(choice) {
        case 'U': pos.second += d;
                  break;
        case 'D': pos.second -= d;
                  break;
        case 'L': pos.first -= d;
                  break;
        case 'R': pos.first += d;
                  break;
    }
}

bool reaches_somehow(pair<int, int> pos, int len) {
    int disp = abs(pos.first - x) + abs(pos.second - y);
    if(disp % 2 == len % 2) 
        return len >= disp;
    return false;   
}

bool doable(int string_len) {
    pair<int, int> now = {0, 0};
    for(int i = string_len; i < n; i++) {
        update(s[i], now, 1);
    }
    int l = 0, r = string_len;
    while(true) {
        if(reaches_somehow(now, string_len)) {
            return true;
        }
        if(r == n) break;
        update(s[l++], now, 1);     // Add
        update(s[r++], now, -1);    // Remove
    }
    return false;
}
int main() {
    cin >> n >> s;
    cin >> x >> y;

    if(not doable(s.length())) {
        cout << -1 << endl;
        return 0;
    }

    int l = -1, r = n;
    while(l < r - 1) {
        int mid = (l + r) >> 1;
        if(doable(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

