#include <bits/stdc++.h>
using namespace std;

double solve() {
    double d;
    cin >> d;
    double a = 1, b = d;
    if(d == 0) {
        cout << "N\n";
        return 0;
    }

    while(abs((a + b) - (a * b)) > 1e-6) {
        cout << a << ' ' << b << endl;
        if(a + b > d or a * b > d) {
            double mid = (a + b) / 2;
            b = mid;
        }
        else if(a + b < d or a * b < d) {
            double mid = (a + b) / 2;
            a = mid;
        }
    }
    cout << endl;
    cout << a << ' ' << b << endl;
}


int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
