#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x;
    cin >> x;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= x; j++) {
            if(i * j > x and i / j < x and i % j == 0) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
