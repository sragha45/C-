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

int solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    set<string> possible;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            string x = "";
            for(int k = i; k <= j; k++) {
                x += b[k];
            }
            sort(x.begin(), x.end());
            possible.insert(x); 
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j <= n; j++) {
            string x = "";
            for(int k = i; k <= j; k++) {
                x += a[k];
            }
            sort(x.begin(), x.end());
            if(possible.count(x)) {
                // cout << x << endl;
                ans++;
            }
        }
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    // cout << (int)'a';
}
