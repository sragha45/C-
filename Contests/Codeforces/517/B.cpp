#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n - 1], b[n - 1];
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < n - 1; j++) {
        cin >> b[j];
    }
    int t[n];
    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        if((a[i] & b[i]) == b[i]) {
            if(i > 0 and ((a[i] & b[i]) == (a[i - 1] & b[i - 1]) or 
                    (a[i] & b[i]) == (a[i - 1] | b[i - 1]))) {
                ok = true;
            }
        }
        else {
            ok = false;
            break;
        }
    }

    t[0] = a[0] & b[0];
    t[1] = a[0] | b[0];

/*  if(!ok) {
        cout << "NO";
        return 0;
    }
*/
    for(int i = 1; i < n - 1; i++) {
        int val = (a[i] & b[i]);
        if(t[i] == val) {
            t[i + 1] = (a[i] | b[i]);
        }
        else if(t[i - 1] == val){
            swap(t[i], t[i - 1]);
            t[i + 1] = (a[i] | b[i]);
        }
        else {
            val = a[i] | b[i];
            if(t[i] == val) {
                t[i + 1] = (a[i] & b[i]);
            }
            else if(t[i - 1] == val) {
                swap(t[i], t[i - 1]);
                t[i + 1] = (a[i] & b[i]);
            }
            else {
                ok = false;
            }
        }
    }
    if(!ok or ((b[0] & a[0]) != b[0])) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << t[i] << ' ';
    }
}
