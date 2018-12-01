#include <bits/stdc++.h>
using namespace std;

struct tree {
    int parent;
    int left, right;
};

set<int> visited;
int ans = 0, mx_so_far = 0;
vector<tree> v;

void dfs(int node, int len) {
    if(node == -1) return;
    if(visited.count(node) != 0) {
        return;
    }
    visited.insert(node);
    cerr << node << ' ' << len << endl;
    dfs(v[node].parent, len + 1);
    dfs(v[node].left, len + 1);
    dfs(v[node].right, len + 1);
    if(len > mx_so_far) {
        mx_so_far = len;
        ans = node;
    }
    visited.erase(node);
}


int main() {
    clock_t timer = clock();
    cerr << setprecision(6);

    int n;
    cin >> n;
    v.assign(n + 1, tree());
    for(int i = 0; i <= n; i++) {
        v[i].parent = v[i].left = v[i].right = -1;
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[y].parent = x;
        if(v[x].left == -1) {
            v[x].left = y;
        }
        else {
            v[x].right = y;
        }
    }
    dfs(1, 0);
    cout << ans;
    cerr << endl << "CLOCKS_PER_SEC : "  << CLOCKS_PER_SEC << endl;
    cerr << "TIME ELAPSED: " << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << endl;
}

