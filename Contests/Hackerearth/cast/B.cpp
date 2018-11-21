#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    long long prefix[n];
    prefix[0] = a[0].first;
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i].first;
    }
    
    long long ans[n];
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), make_pair(a[i].first + k, -1));

        if(it == a.end()) {
            ans[a[i].second] = 0;          
        }
        else {
            long long res = 0;
            int idx = it - a.begin();
            //cout << idx << ' ' << prefix[n - 1] << ' ' << prefix[idx - 1] << endl;
            res = (prefix[n - 1] - prefix[idx - 1]) - (n - idx) * a[i].first;
            ans[a[i].second] = res;
        }

        auto it2 = upper_bound(a.begin(), a.end(), make_pair(a[i].first - k, -1));
        int idx = it2 - a.begin();
//        cout << a[i].first << ' ' << (*it2).first << endl;
        
        if(a[i].first - (*it2).first < k) {
            if(idx != 0) {
                idx--;
            }
            else continue;
        }
            long long res = 0;
            res = ((idx + 1) * a[i].first) - prefix[idx];
   //         cout << a[i].first << ' ';
  //          cout << idx << ' ' << prefix[idx] << endl;
            ans[a[i].second] += res;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
