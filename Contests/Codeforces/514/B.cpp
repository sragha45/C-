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

int n, m;
int a[1002][1002], b[1002][1002];

bool ok(int a, int b) {
    return (a + 2 < n and b + 2 < m);
}

bool allok(int i, int j) {
    if(a[i][j] == 0) {
        return false;
    }
    if(a[i + 1][j] == true and 
       a[i + 2][j] == true and
       a[i][j + 1] == true and 
       a[i][j + 2] == true and 
       a[i + 1][j + 2] == true and 
       a[i + 2][j + 1] == true and 
       a[i + 2][j + 2] == true)
        return true;
    else return false;
}

int main() {
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            a[i][j] = (ch == '#');
        }
    }

    memset(b, 0, sizeof b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ok(i, j)) {

                if(allok(i, j)){
                    for(int p = i; p < i + 3; p++) {
                        for(int q = j; q < j + 3; q++) {
                            if(p - i == 1 and q - j == 1) {
                                if(b[p][q] == 0) continue;
                            }
                            b[p][q] = a[p][q];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(ok(i, j)) {
                if(allok(i, j)){
                    // cout << i << ' ' << j << endl;
                    for(int p = i; p < i + 3; p++) {
                        for(int q = j; q < j + 3; q++) {
                            if(p - i == 1 and q - j == 1) {
                                if(b[p][q] == 0) continue;
                            }
                            b[p][q] = a[p][q];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
