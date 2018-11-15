#include <bits/stdc++.h>
using namespace std;

/*long long brute(long long n) {
    long long ans = 0;
    while(n != 0) {
        long long d = 2;
        for(; d * d <= n; d++) {
            while(n != 0 and n % d == 0) {
                n -= d;
                ans ++;
            }
        }
        if(d * d > n) return ++ans;
    }
    return ans;
}
*/

int main() {
    long long n;
    cin >> n;
//    bool primes[n + 1];
//    for(long long i = 0; i <= n; i++) {
//        primes[i] = true;
//    }
//    vector<long long> v;
//    long long d = 2;
//    for(long long d = 2; d * d <= n; d++) {
//        if(primes[d]) {
//        for(long long i = 2 * d; i <= n; i += d) {
//            primes[i] = false;
//        }
//        v.push_back(d);
//        }
//    }
//    for(long long x: v) {
//       if(n % x == 0) {
//          cout << n / x;
//          return 0;
//       }
//    }
    long long d = 2;
    while(d * d <= n) {
        bool ok = true;
        if(n % d == 0)  {
            long long x = 2;
            while(x * x <= d ) {
                if(d % x == 0) {
                    ok = false;
                }
            }
            if(ok) {
                cout << n /d;
                return 0;
            }
        }
        d++;
    }
    cout << 1;

   // cout << brute(n);
}
