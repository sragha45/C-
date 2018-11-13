#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void populate() {
    for(int i = 2; i * i <= 1e6; i++) {
        v.push_back(

int main() {
    int n;
    cin >> n;
    int ops = 0;
    bool ok = false;
    do {
        ok = false;
        for(int i = 1; i * i <= 1e6; i++) {
            if((i * i) % n == 0) {
                if(i * i == n) {
                    ops += 1;
                    ok = true;
                    cout << i << ' ' << n << ' ' << ops << endl;
                    n = i;
                    break;
                }
                if(i < n) {
                    ops += 2;
                    ok = true;
                    cout << i << ' ' << n << ' ' << ops << endl;;
                    n = i;
                    break;
                }
            }
        }
    }while(ok);
    cout << n << ' ' << ops << endl;
}
