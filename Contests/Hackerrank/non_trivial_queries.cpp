#include <bits/stdc++.h>
using namespace std;

long long count(long long a, long long x) {
    bitset<64> bits_a(a), bits_x(x);
    if((int)log2(a) < log2(x)) return 0;
    int bit_count_x = __builtin_popcountll(x);
    long long ans = ((a & x) == x);
    for(int i = 63; i >= 0; i--) {  
        if(bits_x[i] == 1) {
            bit_count_x--;
            continue;
        }
        if(bits_a[i] == 1) {
            int cnt = i - bit_count_x;
            ans += (1LL << cnt);
        }
    }
    return ans;
}

void solve(long long a, long long b, long long x) {
    cout << (count(b, x) - count(a - 1, x)) << endl;;
//    cout << count(b, x) << ' ' << count(a - 1, x);
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        long long l, r, x;
        cin >> l >> r >> x;
        solve(l, r, x);
    }
}

