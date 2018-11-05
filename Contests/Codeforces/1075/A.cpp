#include <bits/stdc++.h>
using namespace std;

int main() {
   long long  n;
    cin >> n;
    pair<long long, long long> white = {1, 1};
    pair<long long, long long> black = {n, n};
    long long x, y;
    cin >> x >> y;

    long long d_w = max(x - white.first, y - white.second);
    long long d_b = max(black.first - x, black.second - y);

    if(d_w <= d_b) {
        cout << "White";
    }
    else {
        cout << "Black";
    }
}
