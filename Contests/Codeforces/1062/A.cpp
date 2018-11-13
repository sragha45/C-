#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int start = 0;
    int end = 0;
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[end] == 1) {
            end = i;
        }
        else {
            res = max(end - start - 1, res);
            end = i;
            start = i;
        }
    }
    if(end == n - 1 and start != 0) {
        cout << max(res, end - start - 1);
    }
    else
        cout << max(res, end - start) << endl;
}
