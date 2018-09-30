#include<stdio.h>  
#include <bits/stdc++.h>
#include<stdlib.h>

using namespace std;

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void maximum(vector<int> &a, vector<int> &b) {
    for(int i = 0; i < 26; i++) {
        b[i] = max(b[i], a[i]);
    }
}

void populate(vector<int> &a, string s) {
    for(char c: s) {
        a[c - 'a']++;
    }
} 

bool equal(vector<int> &a, vector<int> &b) {
    for(int i = 0; i < 26; i++) {
        if(b[i] > a[i]) {
            return false;
        }
    }
    return true;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool cmp1(pair<int, int> a, int b) {
    return a.second < b;
}

int main() {
    long long s;
    cin >> s;
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);

    for(auto x: a) {
        cout << x.first << ' ' << x.second << endl;
    }

    long long speed = 0,  ans = 0, point = 0, i = 0;
    while(i < n and a[i].second <= s) {
        ans += (a[i].second - point) * speed;
        point = a[i].second;
        speed += a[i].first;
        ans += a[i].first;
        i++;
        if(a[i].second > s) break;
    }
    cout << ans << endl;
    i -= (i ? 1 : 0);
    cout << (long long)ans + (s - a[i].second) * speed;
}
