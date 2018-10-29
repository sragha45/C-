#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        if(i % 2 == 0) {
            n -= n % 2;
            m += n / 2;
            n -= n / 2;
        }
        else {
            m -= m % 2;
            n += m / 2;
            m -= m / 2;
        }
    }
    cout << n << ' ' << m;
}
