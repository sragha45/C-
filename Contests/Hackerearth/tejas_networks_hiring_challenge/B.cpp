#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int n;
    cin >> n;
    ll sum[n];
    for(int i = 0; i < n; i++) {
        sum[i] = 0;
    }
    int q;
    cin >> q;
    deque<ll> dq;
    int ptr = 0;
    while(q--) {
        int choice;
        cin >> choice;
        if(choice == 1) {
            ll x, y;
            cin >> x >> y;
            dq.emplace_back(y);
            dq.emplace_front(x);
        }
        else {
            if(dq.empty()) continue;

            ll one = dq.front(), two = dq.back();
            dq.pop_back(); dq.pop_front();

            ll dist;
            cin >> dist;
            ptr += (dist % n);
            ptr %= n;

            sum[ptr] += one;
            sum[(ptr + n / 2) % n] += two;
        }
    }
    ll m = 0;
    for(int i = 0; i < n; i++) {
        m = max(m, sum[i]);
    }
    for(int i = 0; i < n; i++) {
        if(sum[i] == m) {
            cout << i + 1 << ' ' << sum[i];
            return 0;
        }
    }
}
