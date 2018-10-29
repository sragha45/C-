#include <bits/stdc++.h>
using namespace std;

long long count(long long a, long long x) {
    if(a < x) return 0;
    if(x == 0) return a;
    bitset<64> bits_a(a), bits_x(x);
    long long ans = 0;
    int oo = 0, io = 0;
    int poison = 0;
    for(int i = 63; i >= 0; i--) {
        if(bits_a[i] == 1 and bits_x[i] == 0) {
            io++;
        }
        else if(bits_x[i] == 0) {
            oo++;
        }
        else if(bits_a[i] == 0 and bits_x[i] == 1) {
            poison = 1;
        }
    }
    for(int i = 63; i >= 0; i--) {
        if(bits_a[i] == 1 and bits_x[i] == 0) {
            io--;
        }
        else if(bits_x[i] == 0) {
            oo--;
        }
        if(bits_a[i] == 1 and bits_x[i] == 0) {
            cout << io << ' ' << oo << ' ' << poison << endl;
            ans += (2LL << io);
            if(oo > 0)
                ans += (1LL << oo);
            return ans - poison;
        }
    }
    return 0;
}

long long solve(long long a, long long b, long long x) {
    cout << count(b, x) << ' ' << count(a - 1, x) << endl;
 //   count(b, x);
    return (count(b, x) - count(a - 1, x));
}

long long answer(long long a, long long b, long long x) {
    long long ans = 0;
    for(; a <= b; a++) {
        ans += ((a & x) == x);
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    srand(time(NULL));
    while(q--) {
//        long long l = rand() % 20, r = rand() % 20, x = rand() % 20;
//        l = min(l, r);
//        r = max(l, r);
//        cout << l << ' ' << r << ' ' << x << endl;
//        cout << solve(l, r, x) << ' ' << answer(l, r, x) << endl;
//        assert(solve(l, r, x) == answer(l, r, x));
//        cout << q << " ok\n";

        int l, r, x;
        cin >> l >> r >> x;
        cout << solve(l, r, x);

    }
}

