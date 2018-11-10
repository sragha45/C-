#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto cmp = [] (pair<int, int> a, pair<int, int> b)-> bool {
                    if(a.second != b.second) {
                        return a.second < b.second;
                    }
                    else return a.first < b.first;
    };
    sort(a, a + n, cmp);
    int right = 0, left = 0;
    int ans = 0;
    for(auto x: a) {
        if(x.first > left) {
            left = x.second;
            ans++;
        }
    }
    cout << ans;
}
