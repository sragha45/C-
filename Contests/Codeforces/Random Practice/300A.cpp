#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int num_pos = 0, num_neg = 0, num_zer = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num_pos += (a[i] > 0);
        num_neg += (a[i] < 0);
        num_zer += (a[i] == 0);
    }
    sort(a, a + n);
    cout << 1 << " " << a[0];
    vector<int> p;
    for(int i = 1; i < n; i++) {
        if(a[i] != 0) 
            p.push_back(a[i]);
    }
    cout << endl;
     cout << num_pos + num_neg - 1 << ' ';
    for(int i: p) {
        cout << i << ' ';
    }
    cout << endl;
   cout << num_zer << " ";
    for(int i = 0; i < num_zer; i++) {
        cout << 0 << " ";
    }
}
