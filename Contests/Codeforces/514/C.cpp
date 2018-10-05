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
    int n;
    cin >> n;
    if(n == 3) {
        cout << "1 1 3";
        return 0;
    }
    if(n == 2) {
        cout << "1 2";
        return 0;
    }
    if(n == 1) {
        cout << "1";
        return 0;
    }
    int d = 2, po = 1, cnt = 0;
    vector<int> a;
    int nn = n;
    while(n) {
        int p = nn / d;
        for(int i = 0; i < n - p; i++) {
            a.push_back(po);
        }
        n -= ceil((double)n / d);
        po <<= 1;
        // cout << n << endl;
    }
    for(int x : a) {
        cout << x << ' ';
    }
}
