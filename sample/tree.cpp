#include <bits/stdc++.h>
using namespace std;

struct edge {
    int left, right;
    edge() {
        left = right = -1;
    }
};

vector<edge> tree;
int n;

int solve(int node, bool taken) {
    if(node == -1) return 0;
    cout << node << ' ' << taken << endl;
    int ret = 0;
    if(!taken) {
        ret = node + solve(tree[node].left, 1) + solve(tree[node].right, 1);
    }
    ret = max(ret, solve(tree[node].left, 0) + solve(tree[node].right, 0));
    return ret;
}

int main() {
    cin >> n;
    tree.assign(n + 1, edge());
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if(tree[u].left == -1) tree[u].left = v;
        else tree[u].right = v;
    }
    for(int i = 0; i <= n; i++) {
        cerr << "Node: " << i << " Left: " << tree[i].left << " Right: " << tree[i].right << endl;
    } 
    cout << solve(1, 0) << endl;
}
