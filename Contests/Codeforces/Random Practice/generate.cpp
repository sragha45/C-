#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    srand(time(NULL));

    cout << n << endl;
    for(int i = 0 ; i < 2 * n; i++) {
        cout << rand() << ' ';
    }
}
