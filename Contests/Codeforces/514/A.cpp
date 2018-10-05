#include<stdio.h>  
#include <bits/stdc++.h>
#include<stdlib.h>

using namespace std;


typedef long long ll;

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


const ll INF = 2e9;

int main() {
    ll n, l, a;
    cin >> n >> l >> a;
    ll prev = 0, curr = 0, ans = 0; 
    while(n--) {
        ll from, d;
        cin >> from >> d;
        curr = from + d;
        ans += (from - prev) / a;
        prev = curr;
    }   
    // cout << curr << endl;
    ans += (l - curr) / a;
    cout << ans;
}
