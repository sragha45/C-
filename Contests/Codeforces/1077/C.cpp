#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        sum += a[i].first;
    }
    sort(a, a + n);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        sum -= a[i].first;
        int l = 0, r = n - 1;
        bool ok = false;
//        cout << endl << "Choosing: " << sum << endl;;
        while(l <= r) {             // check this
            int mid = (l + r) / 2;
            long long x = sum - a[mid].first;
            cout << mid << ' ' << x << endl;
            if(a[mid].first < x) {
                l = mid + 1;
            }
            else if(a[mid].first > x) {
                r = mid - 1;
            }
            else {
                cerr << "Debug : " << mid << ' ' << i << endl;
                ok = (i != mid);
  //              cout << "Answer: " << x << ' ' << i << endl;
                break;
            }
        }
        if(ok) {
            ans.push_back(a[i].second);
        }
        sum += a[i].first;
    }
    cout << ans.size() << endl;
    for(int i : ans) {
        cout << i + 1 << ' ';
    }
}

