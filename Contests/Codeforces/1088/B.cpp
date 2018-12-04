#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long x = 0;
    int cnt = 0;
    int ptr = 0;
    for(int i = 0; i < k; i++) {
        if(ptr >= n) {
            cout << 0 << endl;
        }
        else if(a[ptr] - x != 0) {
            cout << a[ptr] - x << endl;
            x += a[ptr] - x;
        }
        else {
            i--;
        }
        ptr++;

    }
}
