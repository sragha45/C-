#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<int> height, euler, first, segtree;
    vector<bool> visited;

void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
        if (!visited[to]) {
            dfs(adj, to, h + 1);
            euler.push_back(node);
        }
    }
}

void input(vector<vector<int>> &adj) {
	int e;
	cin >> e;
	while(e--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > adj(n);
    height.resize(n);
    input(adj);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(adj, 0);
    int m = euler.size();

    cout << "First: ";
    for(int x: first) cout << x << ' ';
    cout << endl;
	cout << "Height: ";
	for(int x: height) cout << x << ' ';
	cout << endl;
	cout << "Euler: ";
	for(int x: euler) cout << x << ' ';
	cout << endl;
}