#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int p[n];
    p[0] = (s[0] == '1');
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1] + (s[i] == '1');
    }
    
    while(q--) {
        int sum = 0;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ones;
        if(l == 0) 
            ones = p[r];
        else
            ones = p[r] - p[l - 1];

        int zeros = (r - l + 1 - ones);
//        cout << zeros << ' ' << ones << endl;
        sum = power(2, ones);
        sub(sum, 1);
        for(int i = 0; i < zeros; i++) {
            add(sum, sum);
        }
        cout << sum << endl;
    }
    
}
    
