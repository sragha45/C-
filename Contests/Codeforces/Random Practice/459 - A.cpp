//http://codeforces.com/problemset/problem/459/A

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);
    
    int pair<int, int> x, y;
    cin >> x.first >> x.second >> y.first >> y.second;

    if(y < x) swap(x, y);

    if(x.first == y.first) {
        int d = abs(y.second - x.second);
        cout << x.first + d << ' ' << x.second + d << ' ' << x.first + d << ' ' y.second;
    }
    else if(y.first - x.first == y.second - x.second) {
        int d = y.first - x.first;
        cout << x.first + d << ' ' x.second << ' ' << y.first << ' ' << y.second;
    }

    return 0;
}
