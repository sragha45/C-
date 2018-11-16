#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> f;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<pair<int, int> > data(f.begin(), f.end());
    for(auto &x: data) {
        swap(x.first, x.second);
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >  >pq;
    for(auto x: data) {
        pq.push(x);
//        cout << x.first << ' ' << x.second << endl;
    }
/*    while(!pq.empty()) {
        pair<int, int> x = pq.top();
        cout << x.second << ' ' << x.first << endl;
        pq.pop();
    }
    */
//    return 0;

    map<int, int> taken;
    while(!pq.empty() and k > 0) {
        pair<int, int> x = pq.top();
        cout << x.second  << ' ';// << x.first << endl;
        pq.pop();
        taken[x.second] += 1;
        x.first = f[x.second] / (taken[x.second] + 1);
        pq.push(x);
        k--;
    }
}
