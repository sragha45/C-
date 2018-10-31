#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], h[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> h[i];
    }
    pair<int, int> l[n], r[n];
    l[0] = {a[0], 1};
    r[0] = {a[0] + h[0], 1};
    for(int i = 1; i < n; i++) {
        int mn = r[i - 1].first;
        // Prev to right, present to left
        if(mn < a[i] - h[i]) {
            l[i] = {a[i], max(l[i - 1].second, r[i - 1].second) + 1};
        }
        else {
            // Prev to left, present to left
            if(a[i] - h[i] > l[i - 1].first) {
                l[i] = {a[i], l[i - 1].second + 1};
            }
             
            //Unable to fell left
            else {
                if(r[i - 1].first < a[i])
                    l[i] = {a[i], max(r[i - 1].second, l[i - 1].second)};
                else
                    l[i] = {a[i], l[i - 1].second};
            }
        }

       if(a[i] > r[i - 1].first) { 
           r[i] = {a[i] + h[i], max(l[i - 1].second, r[i - 1].second) + 1};
       
       }
       else {
           if(l[i - 1].first < a[i])
               r[i] = {a[i] + h[i], l[i - 1].second + 1};
           else
               r[i] = {a[i] + h[i], l[i - 1].second};
       }

    } 
    /*for(int i = 0; i < n; i++) {
       cerr << l[i].first << ' ' << l[i].second << ' ' << r[i].first << ' ' << r[i].second << endl;
    }*/
    cout << max(l[n - 1].second, r[n - 1].second);
}
