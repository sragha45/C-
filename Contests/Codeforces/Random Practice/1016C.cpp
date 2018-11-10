#include <bits/stdc++.h>
using namespace std;

const int lmt = 3e5 + 10;
int a[2][lmt], n;
set<pair<int, int> > v;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y) {
    return x < 2 and y < n and x >= 0 and y >= 0;
}

int solve(pair<int, int> pos, int time) {
    int x = pos.first, y = pos.second;
    
    if(v.count(pos)) return 0;

    v.insert(pos);

    int res = time * a[x][y];
    int sum = 0;

    cout << x << ' ' << y << ' ' << ' ' << time << ' ' << res << endl;

    for(int i = 0; i < 4; i++) {
        int d_x = dx[i] + x;
        int d_y = dy[i] + y;
        if(ok(d_x, d_y)) {  
            sum = max(sum, solve({d_x, d_y}, time + 1) + res);
        }
    }

    v.erase(pos);

    return sum;
}

int main() {
    cin >> n;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(make_pair(0, 0), 0);
}
