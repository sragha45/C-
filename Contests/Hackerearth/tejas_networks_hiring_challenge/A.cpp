#include <bits/stdc++.h>
using namespace std;

int matrix[502][502];
int cm[502][502];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool ok(int x, int y, int ndx, int ndy) {
    return ndx < n and ndy < m and ndx >= 0 and ndy >= 0
            and (__gcd(matrix[x][y], matrix[ndx][ndy]) == 1);
}

bool ok(int x, int y) {
    return x < n and y < m and x >= 0 and y >= 0;
}

void dfs(int x, int y, int cn, int &sz) {
    if(cm[x][y] != 0) return;
    cm[x][y] = cn;
    sz++;   
    for(int i = 0; i < 4; i++) {
        int ndx = x + dx[i];
        int ndy = y + dy[i];
        if(ok(x, y, ndx, ndy)) {
            dfs(x + dx[i], y + dy[i], cn, sz);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            cm[i][j] = 0;
        }
    }
    map<int, int> f;
    int component_no = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cm[i][j] == 0) {
                int component_sz = 0;
                dfs(i, j, component_no, component_sz);
                f[component_no] = component_sz;
        //        cout << component_no << ' ' << component_sz << endl;
                component_no++;
            }
        }
    }

   /* for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << cm[i][j] << ' ';
        }
        cout << endl;
    }
    */
    set<int> added;
    int ans = 0, res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res = f[ cm[i][j] ];
            added.clear();
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(ok(x, y)) {
                    if(cm[i][j] != cm[x][y]) {
        //                cout << "(" << i << ", " << j << ")(" << x << ", " << y << ")\n";
                        if(!added.count(cm[x][y])) {
                            res += f[ cm[x][y] ];
                            added.insert(cm[x][y]);
                        }
                    }
                }
            }
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
}
